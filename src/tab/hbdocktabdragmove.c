#include "hbdocktabdragmove.h"

void hbDockTabDragMove(
      HB_DOCK_TAB_DRAG * pDrag,
      POINT pt )
{
   if( !pDrag->Dragging )
      return;

   pDrag->CurrentPoint = pt;
}