#include <stdlib.h>

#include "hbdockmanagerautohide.h"
#include "hbdockmanagerdock.h"
#include "hbdockmanagerlayout.h"
#include "hbdockpaneldock.h"
#include "hbdockconfig.h"

static HB_DOCK_AUTOHIDE * hbDockManagerFindAutoHide(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   int i;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE * pAutoHide =
         ( HB_DOCK_AUTOHIDE * ) hbDockArrayGet(
            &pManager->AutoHideManager.Panes,
            i );

      if( pAutoHide != NULL && pAutoHide->Panel == pPanel )
         return pAutoHide;
   }

   return NULL;
}

static void hbDockManagerCalcAutoHideRects(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_SITE Site,
   RECT * pHidden,
   RECT * pVisible )
{
   RECT rc;
   int cx;
   int cy;

   GetClientRect(
      pManager->hMainWnd,
      &rc );

   cx = pPanel->DockSize.cx > 0 ?
        pPanel->DockSize.cx :
        pPanel->MinWidth;

   cy = pPanel->DockSize.cy > 0 ?
        pPanel->DockSize.cy :
        pPanel->MinHeight;;

   switch( Site )
   {
      case HB_DOCKSITE_RIGHT:

         SetRect(
            pHidden,
            rc.right - HBDOCK_AUTOHIDE_STRIP,
            rc.top,
            rc.right,
            rc.bottom );

         SetRect(
            pVisible,
            rc.right - cx,
            rc.top,
            rc.right,
            rc.bottom );
         break;

      case HB_DOCKSITE_TOP:

         SetRect(
            pHidden,
            rc.left,
            rc.top,
            rc.right,
            rc.top + HBDOCK_AUTOHIDE_STRIP );

         SetRect(
            pVisible,
            rc.left,
            rc.top,
            rc.right,
            rc.top + cy );
         break;

      case HB_DOCKSITE_BOTTOM:

         SetRect(
            pHidden,
            rc.left,
            rc.bottom - HBDOCK_AUTOHIDE_STRIP,
            rc.right,
            rc.bottom );

         SetRect(
            pVisible,
            rc.left,
            rc.bottom - cy,
            rc.right,
            rc.bottom );
         break;

      case HB_DOCKSITE_LEFT:
      default:

         SetRect(
            pHidden,
            rc.left,
            rc.top,
            rc.left + HBDOCK_AUTOHIDE_STRIP,
            rc.bottom );

         SetRect(
            pVisible,
            rc.left,
            rc.top,
            rc.left + cx,
            rc.bottom );
         break;
   }
}

void hbDockManagerAutoHidePanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;
   HB_DOCK_SITE Site;

   if( pManager == NULL || pPanel == NULL )
      return;

   if( hbDockManagerFindAutoHide( pManager, pPanel ) != NULL )
      return;

   Site = hbDockPanelGetDockSite( pPanel );

   hbDockManagerUndockPanel(
      pManager,
      pPanel );

   pAutoHide = ( HB_DOCK_AUTOHIDE * ) calloc(
      1,
      sizeof( HB_DOCK_AUTOHIDE ) );

   if( pAutoHide == NULL )
      return;

   hbDockAutoHideInit(
      pAutoHide,
      pPanel );

   hbDockManagerCalcAutoHideRects(
      pManager,
      pPanel,
      Site,
      &pAutoHide->HiddenRect,
      &pAutoHide->VisibleRect );

   hbDockAutoHideEnable(
      pAutoHide,
      1 );

   hbDockAutoHideCollapse(
      pAutoHide );

   if( pPanel->hWnd != NULL )
      ShowWindow(
         pPanel->hWnd,
         SW_HIDE );

   pPanel->Visible = 0;

   hbDockArrayAdd(
      &pManager->AutoHideManager.Panes,
      pAutoHide );

   hbDockManagerLayout(
      pManager );
}

void hbDockManagerAutoHideRestore(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;
   HB_DOCK_SITE Site;
   int i;

   if( pManager == NULL || pPanel == NULL )
      return;

   pAutoHide = hbDockManagerFindAutoHide( pManager, pPanel );

   if( pAutoHide == NULL )
      return;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      if( hbDockArrayGet(
             &pManager->AutoHideManager.Panes,
             i ) == pAutoHide )
      {
         hbDockArrayRemove(
            &pManager->AutoHideManager.Panes,
            i );
         break;
      }
   }

   free( pAutoHide );

   Site = hbDockPanelGetDockSite( pPanel );

   pPanel->Visible = 1;

   if( pPanel->hWnd != NULL )
      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );

   hbDockManagerDockPanelAt(
	   pManager,
	   pManager->LayoutTree.Root,
	   pPanel,
	   Site );
   hbDockManagerLayout(
      pManager );
}

void hbDockManagerAutoHideExpand(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;

   if( pManager == NULL || pPanel == NULL )
      return;

   pAutoHide = hbDockManagerFindAutoHide( pManager, pPanel );

   if( pAutoHide == NULL || pAutoHide->Expanded )
      return;

   hbDockAutoHideExpand( pAutoHide );

   if( pPanel->hWnd != NULL )
   {
      MoveWindow(
         pPanel->hWnd,
         pPanel->Rect.left,
         pPanel->Rect.top,
         pPanel->Rect.right  - pPanel->Rect.left,
         pPanel->Rect.bottom - pPanel->Rect.top,
         TRUE );

      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );

      BringWindowToTop(
         pPanel->hWnd );
   }
}

void hbDockManagerAutoHideCollapse(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;

   if( pManager == NULL || pPanel == NULL )
      return;

   pAutoHide = hbDockManagerFindAutoHide( pManager, pPanel );

   if( pAutoHide == NULL || !pAutoHide->Expanded )
      return;

   hbDockAutoHideCollapse( pAutoHide );

   if( pPanel->hWnd != NULL )
      ShowWindow(
         pPanel->hWnd,
         SW_HIDE );
}

HB_DOCK_PANEL * hbDockManagerAutoHideHitTest(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   int i;

   if( pManager == NULL )
      return NULL;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE * pAutoHide =
         ( HB_DOCK_AUTOHIDE * ) hbDockArrayGet(
            &pManager->AutoHideManager.Panes,
            i );

      if( pAutoHide != NULL &&
          PtInRect( &pAutoHide->HiddenRect, pt ) )
         return pAutoHide->Panel;
   }

   return NULL;
}
