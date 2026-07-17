#include "hbdockmanagermousemove.h"

#include "hbdragpreviewmousemove.h"

void hbDockManagerMouseMove(
      HB_DOCK_MANAGER * pManager,
      POINT pt )
{
    if( !pManager->Dragging )
        return;

    hbDragPreviewMouseMove(
        &pManager->Preview,
        pt );
}