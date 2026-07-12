#include <string.h>

#include "hbdocktabdrag.h"

BOOL hbDockTabDragBegin(
   HB_DOCK_TAB_DRAG * pDrag,
   HB_DOCK_TAB_GROUP * pGroup,
   UINT Index,
   POINT pt )
{
   ZeroMemory(
      pDrag,
      sizeof(*pDrag));

   pDrag->Dragging = TRUE;

   pDrag->SourceIndex = Index;

   pDrag->StartPoint = pt;

   pDrag->CurrentPoint = pt;

   pDrag->pSourceGroup = pGroup;

   return TRUE;
}

void hbDockTabDragEnd(
   HB_DOCK_TAB_DRAG * pDrag )
{
   pDrag->Dragging = FALSE;
}