#include "hbdockmanagermousemove.h"

#include "hbdockdragcontroller.h"

void hbDockManagerMouseMove(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   if( pManager == NULL )
      return;

   if( !pManager->Dragging )
      return;

   if( pManager->pDragController == NULL )
      return;

   hbDockDragControllerMove(
      pManager->pDragController,
      pt );
}