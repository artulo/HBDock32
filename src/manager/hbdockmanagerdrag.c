#include "hbdockmanagerdrag.h"

#include "hbdockdragcontroller.h"
#include "hbdockmanagerdock.h"
#include "hbdockmanagerlayout.h"
#include "hbdockmanagerfloat.h"

/*
void hbDockManagerBeginDrag(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   POINT pt )
{
   if( pManager == NULL )
      return;

   if( pPanel == NULL )
      return;


   pPanel->Visible = FALSE;


   hbDockDragControllerBegin(
      pManager->pDragController,
      pPanel,
      pManager->hMainWnd,
      pt );


   pManager->Dragging = TRUE;
}

*/
int hbDockManagerDragMove(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   if( pManager == NULL )
      return FALSE;


   if( !hbDockDragIsDragging(
          pManager->pDragController ) )
      return FALSE;


   hbDockDragControllerMove(
      pManager->pDragController,
      pt );


   return TRUE;
}



void hbDockManagerEndDrag(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   HB_DOCK_PANEL * pPanel;
   HB_DOCK_GUIDE_TYPE Guide;


   if( pManager == NULL )
      return;


   if( !hbDockDragIsDragging(
          pManager->pDragController ) )
      return;


   pPanel =
      hbDockDragGetPanel(
         pManager->pDragController );


   Guide =
      hbDockDragHitTest(
         pManager->pDragController );


   hbDockDragControllerEnd(
      pManager->pDragController );


   pManager->Dragging = FALSE;


   if( pPanel == NULL )
      return;


   pPanel->Visible = TRUE;


   if( Guide == HB_GUIDE_NONE )
   {
      hbDockManagerFloatPanel(
         pManager,
         pPanel,
         pt );

      return;
   }


   hbDockManagerDockPanel(
      pManager,
      pPanel,
      Guide );


   hbDockManagerLayout(
      pManager );
}



void hbDockManagerCancelDrag(
   HB_DOCK_MANAGER * pManager )
{
   HB_DOCK_PANEL * pPanel;


   if( pManager == NULL )
      return;


   pPanel =
      hbDockDragGetPanel(
         pManager->pDragController );


   hbDockDragControllerCancel(
      pManager->pDragController );


   pManager->Dragging = FALSE;


   if( pPanel != NULL )
      pPanel->Visible = TRUE;
}