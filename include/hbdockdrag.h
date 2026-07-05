#ifndef HBDOCKDRAG_H
#define HBDOCKDRAG_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_DRAG
{
   int   Active;
   POINT StartPoint;
   POINT CurrentPoint;
   RECT  DragRect;
   HWND  hWndSource;

} HB_DOCK_DRAG;

void hbDockDragInit(
   HB_DOCK_DRAG * pDrag );

void hbDockDragBegin(
   HB_DOCK_DRAG * pDrag,
   HWND hWnd,
   POINT pt );

void hbDockDragUpdate(
   HB_DOCK_DRAG * pDrag,
   POINT pt );

void hbDockDragEnd(
   HB_DOCK_DRAG * pDrag );

#ifdef __cplusplus
}
#endif

#endif