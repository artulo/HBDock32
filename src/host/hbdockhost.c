#include <windows.h>
#include <windowsx.h>

#include "hbdockhost.h"
#include "hbdocklayout.h"
#include "hbdockhittest.h"
#include "hbdocktreesplitfind.h"
#include "hbdockcaption.h"
#include "hbdockmouse.h"
#include "hbdockmanagerdrag.h"
#include "hbdockmanagerautohide.h"
#include "hbdockmanagerlayout.h"
#include "hbdockmanagermousemove.h"

#define HBDOCK_DRAG_THRESHOLD_CX   4
#define HBDOCK_DRAG_THRESHOLD_CY   4

BOOL hbDockHostAttach(
   HB_DOCK_HOST * pHost,
   HWND hWnd,
   HB_DOCK_MANAGER * pManager )
{
   if( pHost == NULL )
      return FALSE;

   ZeroMemory(
      pHost,
      sizeof( HB_DOCK_HOST ) );

   pHost->hWnd = hWnd;
   pHost->pManager = pManager;

   if( pManager != NULL )
      pManager->hMainWnd = hWnd;

   return TRUE;
}

void hbDockHostDetach(
   HB_DOCK_HOST * pHost )
{
   if( pHost == NULL )
      return;

   if( pHost->hWnd != NULL )
      KillTimer(
         pHost->hWnd,
         HBDOCK_AUTOHIDE_TIMER_ID );

   pHost->hWnd = NULL;
   pHost->pManager = NULL;
}

void hbDockHostResize(
   HB_DOCK_HOST * pHost )
{
   if( pHost == NULL )
      return;

   if( pHost->pManager == NULL )
      return;

   hbDockPerformLayout(
      pHost->pManager );
}

void hbDockHostInvalidate(
   HB_DOCK_HOST * pHost )
{
   if( pHost == NULL )
      return;

   if( pHost->hWnd != NULL )
      InvalidateRect(
         pHost->hWnd,
         NULL,
         TRUE );
}

/* Encuentra, si lo hay, el nodo hoja bajo pt cuyo caption
 * (franja superior del panel) contiene el punto. */
static HB_DOCK_NODE * hbDockHostFindCaptionAt(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   HB_DOCK_HITTEST Hit;
   RECT rc;

   hbDockHitTestTree(
      pManager->LayoutTree.Root,
      pt,
      &Hit );

   if( Hit.Hit != HB_DOCK_HIT_PANEL || Hit.Node == NULL )
      return NULL;

   rc = Hit.Node->Rect;
   rc.bottom = rc.top + HBDOCK_CAPTION_HEIGHT;

   if( !PtInRect( &rc, pt ) )
      return NULL;

   return Hit.Node;
}

static void hbDockHostUpdateAutoHideHover(
   HB_DOCK_HOST * pHost,
   POINT pt )
{
   HB_DOCK_PANEL * pHit;

   pHit = hbDockManagerAutoHideHitTest(
      pHost->pManager,
      pt );

   if( pHit != NULL && pHit != pHost->HoverAutoHide )
   {
      if( pHost->HoverAutoHide != NULL )
         hbDockManagerAutoHideCollapse(
            pHost->pManager,
            pHost->HoverAutoHide );

      pHost->HoverAutoHide = pHit;

      hbDockManagerAutoHideExpand(
         pHost->pManager,
         pHost->HoverAutoHide );

      SetTimer(
         pHost->hWnd,
         HBDOCK_AUTOHIDE_TIMER_ID,
         HBDOCK_AUTOHIDE_TIMER_MS,
         NULL );

      hbDockHostInvalidate( pHost );
   }
}

static void hbDockHostCheckAutoHideLeave(
   HB_DOCK_HOST * pHost )
{
   POINT pt;
   RECT rc;

   if( pHost->HoverAutoHide == NULL )
      return;

   GetCursorPos( &pt );
   ScreenToClient( pHost->hWnd, &pt );

   /* El panel expandido ocupa su Rect actual mientras
    * esta desplegado (ver hbDockAutoHideExpand). */
   rc = pHost->HoverAutoHide->Rect;

   if( !PtInRect( &rc, pt ) &&
       hbDockManagerAutoHideHitTest(
          pHost->pManager, pt ) != pHost->HoverAutoHide )
   {
      hbDockManagerAutoHideCollapse(
         pHost->pManager,
         pHost->HoverAutoHide );

      pHost->HoverAutoHide = NULL;

      KillTimer(
         pHost->hWnd,
         HBDOCK_AUTOHIDE_TIMER_ID );

      hbDockHostInvalidate( pHost );
   }
}

BOOL hbDockHostHandleMessage(
   HB_DOCK_HOST * pHost,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam )
{
   POINT pt;

   if( pHost == NULL || pHost->pManager == NULL )
      return FALSE;

   switch( uMsg )
   {
      case WM_LBUTTONDOWN:
      {
         HB_DOCK_NODE * pSplitNode;
         HB_DOCK_NODE * pCaptionNode;

         pt.x = GET_X_LPARAM( lParam );
         pt.y = GET_Y_LPARAM( lParam );

  pSplitNode = hbDockTreeFindSplitterAt(
   pHost->pManager->LayoutTree.Root,
   pt );
         if( pSplitNode != NULL )
         {
            hbDockSplitNodeInit(
               &pHost->ActiveSplit,
               pSplitNode );

            hbDockSplitNodeUpdate(
               &pHost->ActiveSplit );

            hbDockSplitterTrackerBegin(
               &pHost->SplitterTracker,
               &pHost->ActiveSplit,
               pt );

            SetCapture( pHost->hWnd );

            return TRUE;
         }

         pCaptionNode = hbDockHostFindCaptionAt(
            pHost->pManager,
            pt );

         if( pCaptionNode != NULL && pCaptionNode->Panel != NULL )
         {
            pHost->PendingDragPanel = pCaptionNode->Panel;
            pHost->PendingDragPoint = pt;

            SetCapture( pHost->hWnd );

            return TRUE;
         }

         return FALSE;
      }

      case WM_MOUSEMOVE:

         pt.x = GET_X_LPARAM( lParam );
         pt.y = GET_Y_LPARAM( lParam );

         if( pHost->SplitterTracker.Tracking )
         {
            hbDockSplitterTrackerMove(
               &pHost->SplitterTracker,
               pt );

            hbDockManagerLayout(
               pHost->pManager );

            hbDockHostInvalidate( pHost );

            return TRUE;
         }

         if( pHost->Dragging )
         {
            hbDockManagerDragMove(
               pHost->pManager,
               pt );

            hbDockHostInvalidate( pHost );

            return TRUE;
         }

         if( pHost->PendingDragPanel != NULL )
         {
            if( hbDockMouseMoved(
                   pHost->PendingDragPoint,
                   pt,
                   HBDOCK_DRAG_THRESHOLD_CX,
                   HBDOCK_DRAG_THRESHOLD_CY ) )
            {
               hbDockManagerBeginDrag(
                  pHost->pManager,
                  pHost->PendingDragPanel,
                  pHost->PendingDragPoint );

               pHost->PendingDragPanel = NULL;
               pHost->Dragging = 1;

               hbDockManagerDragMove(
                  pHost->pManager,
                  pt );

               hbDockHostInvalidate( pHost );
            }

            return TRUE;
         }

         hbDockHostUpdateAutoHideHover(
            pHost,
            pt );

         return FALSE;

      case WM_LBUTTONUP:

         pt.x = GET_X_LPARAM( lParam );
         pt.y = GET_Y_LPARAM( lParam );

         if( pHost->SplitterTracker.Tracking )
         {
            hbDockSplitterTrackerEnd(
               &pHost->SplitterTracker );

            ReleaseCapture();

            return TRUE;
         }

         if( pHost->Dragging )
         {
            hbDockManagerEndDrag(
               pHost->pManager,
               pt );

            pHost->Dragging = 0;

            ReleaseCapture();

            hbDockHostInvalidate( pHost );

            return TRUE;
         }

         if( pHost->PendingDragPanel != NULL )
         {
            /* Fue un click simple, sin arrastre: solo
             * activa el panel bajo el caption. */
            pHost->PendingDragPanel = NULL;

            ReleaseCapture();

            return TRUE;
         }

         return FALSE;

      case WM_CAPTURECHANGED:

         /* Otro control se robo la captura del mouse:
          * cancela cualquier operacion en curso en vez
          * de dejarla en un estado inconsistente. */
         if( pHost->Dragging )
         {
            hbDockManagerCancelDrag(
               pHost->pManager );

            pHost->Dragging = 0;
         }

         if( pHost->SplitterTracker.Tracking )
            hbDockSplitterTrackerEnd(
               &pHost->SplitterTracker );

         pHost->PendingDragPanel = NULL;

         return FALSE;

      case WM_TIMER:

         if( wParam == HBDOCK_AUTOHIDE_TIMER_ID )
         {
            hbDockHostCheckAutoHideLeave(
               pHost );

            return TRUE;
         }

         return FALSE;
   }

   return FALSE;
}
