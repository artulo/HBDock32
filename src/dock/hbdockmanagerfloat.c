#include <stdlib.h>

#include "hbdockmanagerfloat.h"
#include "hbdockmanagerdock.h"
#include "hbdockmanagerlayout.h"
#include "hbdockpanelfloating.h"
#include "hbdockpanelparent.h"

HB_DOCK_FLOATING * hbDockManagerFindFloating(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   int i;

   if( pManager == NULL || pPanel == NULL )
      return NULL;

   for( i = 0; i < pManager->FloatWindows.Count; ++i )
   {
      HB_DOCK_FLOATING * pFloating =
         ( HB_DOCK_FLOATING * ) hbDockArrayGet(
            &pManager->FloatWindows,
            i );

      if( pFloating != NULL && pFloating->Panel == pPanel )
         return pFloating;
   }

   return NULL;
}

void hbDockManagerFloatPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   POINT pt )
{
   HB_DOCK_FLOATING * pFloating;
   RECT rc;
   int cx;
   int cy;

   if( pManager == NULL || pPanel == NULL )
      return;

   if( hbDockPanelIsFloating( pPanel ) )
      return;

   /* Si todavia estaba acoplado (llamada directa, fuera
    * de un drag que ya lo haya desacoplado) lo sacamos
    * del arbol primero. */
   hbDockManagerUndockPanel(
      pManager,
      pPanel );

   pFloating = ( HB_DOCK_FLOATING * ) calloc(
      1,
      sizeof( HB_DOCK_FLOATING ) );

   if( pFloating == NULL )
      return;

   if( !hbDockFloatingCreate(
          pFloating,
          pManager->hInstance,
          pPanel ) )
   {
      free( pFloating );
      return;
   }

   cx = pPanel->DockSize.cx > 0 ?
      pPanel->DockSize.cx : pPanel->MinWidth;

   cy = pPanel->DockSize.cy > 0 ?
      pPanel->DockSize.cy : pPanel->MinHeight;

   SetRect(
      &rc,
      pt.x,
      pt.y,
      pt.x + cx,
      pt.y + cy );

   hbDockFloatingMove(
      pFloating,
      &rc );

   if( pPanel->hWnd != NULL )
   {
      hbDockPanelSetParent(
         pPanel,
         pFloating->hWnd );

      GetClientRect(
         pFloating->hWnd,
         &rc );

      MoveWindow(
         pPanel->hWnd,
         rc.left,
         rc.top,
         rc.right  - rc.left,
         rc.bottom - rc.top,
         TRUE );

      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );
   }

   hbDockFloatingShow(
      pFloating,
      1 );

   pPanel->Floating = 1;
   pPanel->Visible  = 1;

   hbDockArrayAdd(
      &pManager->FloatWindows,
      pFloating );

   hbDockManagerLayout(
      pManager );
}

void hbDockManagerDockPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_NODE * pTargetNode,
   HB_DOCK_SITE Site )
{
   HB_DOCK_FLOATING * pFloating;
   int i;

   if( pManager == NULL || pPanel == NULL )
      return;

   if( !hbDockPanelIsFloating( pPanel ) )
      return;

   pFloating = hbDockManagerFindFloating(
      pManager,
      pPanel );

   if( pFloating != NULL )
   {
      if( pPanel->hWnd != NULL )
         hbDockPanelSetParent(
            pPanel,
            pManager->hWnd );

      hbDockFloatingDestroy(
         pFloating );

      for( i = 0; i < pManager->FloatWindows.Count; ++i )
      {
         if( hbDockArrayGet(
                &pManager->FloatWindows,
                i ) == pFloating )
         {
            hbDockArrayRemove(
               &pManager->FloatWindows,
               i );
            break;
         }
      }

      free( pFloating );
   }

   pPanel->Floating = 0;
   pPanel->Visible  = 1;

   hbDockManagerDockPanelAt(
      pManager,
      pTargetNode,
      pPanel,
      Site );

   hbDockManagerLayout(
      pManager );
}
