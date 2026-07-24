#include <windows.h>

#include "hbdockdragcontroller.h"
#include "hbdockguidemanager.h"
#include "hbdockdrag.h"
#include "hbdockmanagerdock.h"

void hbDockDragControllerInit(
   HB_DOCK_DRAG_CONTROLLER * pController,
   HB_DOCK_MANAGER * pManager )
{
   if( pController == NULL )
      return;

   ZeroMemory(
      pController,
      sizeof( HB_DOCK_DRAG_CONTROLLER ) );

   pController->pManager = pManager;
   pController->pPanel = NULL;

   hbDockDragInit(
      &pController->Drag );
}

BOOL hbDockDragControllerBegin(
   HB_DOCK_DRAG_CONTROLLER * pController,
   HB_DOCK_PANEL * pPanel,
   HWND hWnd,
   POINT pt )
{
   if( pController == NULL )
      return FALSE;

   if( pController->pManager == NULL )
      return FALSE;

   if( pPanel == NULL )
      return FALSE;

   pController->pPanel = pPanel;

   hbDockDragBegin(
      &pController->Drag,
      hWnd,
      pt );

   SetCapture(
      hWnd );

   hbDockGuideManagerMove(
      &pController->pManager->GuideManager,
      pt );

   hbDockGuideManagerShow(
      &pController->pManager->GuideManager );

   return TRUE;
}

void hbDockDragControllerMove(
   HB_DOCK_DRAG_CONTROLLER * pController,
   POINT pt )
{
   if( pController == NULL )
      return;

   if( !pController->Drag.Dragging )
      return;

   hbDockDragUpdate(
      &pController->Drag,
      pt );

   hbDockGuideManagerMove(
      &pController->pManager->GuideManager,
      pt );

   pController->Drag.Guide =
      hbDockDragHitTest(
         pController );
}

void hbDockDragControllerEnd(
   HB_DOCK_DRAG_CONTROLLER * pController )
{
   if( pController == NULL )
      return;

   if( !pController->Drag.Dragging )
      return;

   if( pController->Drag.Guide != HB_GUIDE_NONE )
   {
      hbDockManagerDockPanel(
         pController->pManager,
         pController->pPanel,
         pController->Drag.Guide );
   }

   hbDockGuideManagerHide(
      &pController->pManager->GuideManager );

   ReleaseCapture();

   hbDockDragEnd(
      &pController->Drag );

   pController->pPanel = NULL;
}

void hbDockDragControllerCancel(
   HB_DOCK_DRAG_CONTROLLER * pController )
{
   if( pController == NULL )
      return;

   if( !pController->Drag.Dragging )
      return;

   hbDockGuideManagerHide(
      &pController->pManager->GuideManager );

   ReleaseCapture();

   hbDockDragCancel(
      &pController->Drag );

   pController->pPanel = NULL;
}