#ifndef HBDOCKTABDRAG_H
#define HBDOCKTABDRAG_H

#include <windows.h>
#include "hbdocktabgroup.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_TAB_DRAG
{
   BOOL Dragging;

   UINT SourceIndex;

   POINT StartPoint;

   POINT CurrentPoint;

   HWND hDragWindow;

   HB_DOCK_TAB_GROUP * pSourceGroup;
   HB_DOCK_TAB_GROUP * pTargetGroup;

} HB_DOCK_TAB_DRAG;

BOOL hbDockTabDragBegin(
   HB_DOCK_TAB_DRAG * pDrag,
   HB_DOCK_TAB_GROUP * pGroup,
   UINT Index,
   POINT pt );

void hbDockTabDragEnd(
   HB_DOCK_TAB_DRAG * pDrag );

#ifdef __cplusplus
}
#endif

#endif