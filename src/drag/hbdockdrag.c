#include <windows.h>

#include "hbdockdrag.h"

void hbDockDragInit(
   HB_DOCK_DRAG * pDrag )
{
   if( pDrag == NULL )
      return;

   ZeroMemory(
      pDrag,
      sizeof( HB_DOCK_DRAG ) );

   pDrag->Dragging = FALSE;
   pDrag->Guide = HB_GUIDE_NONE;
}

void hbDockDragBegin(
   HB_DOCK_DRAG * pDrag,
   HWND hWnd,
   POINT pt )
{
   if( pDrag == NULL )
      return;

   pDrag->Dragging = TRUE;

   pDrag->hWndSource = hWnd;

   pDrag->StartPoint = pt;
   pDrag->CurrentPoint = pt;

   pDrag->Guide = HB_GUIDE_NONE;

   SetRect(
      &pDrag->DragRect,
      pt.x,
      pt.y,
      pt.x,
      pt.y );
}

void hbDockDragUpdate(
   HB_DOCK_DRAG * pDrag,
   POINT pt )
{
   if( pDrag == NULL )
      return;

   if( !pDrag->Dragging )
      return;

   pDrag->CurrentPoint = pt;

   pDrag->DragRect.left =
      pDrag->StartPoint.x;

   pDrag->DragRect.top =
      pDrag->StartPoint.y;

   pDrag->DragRect.right =
      pt.x;

   pDrag->DragRect.bottom =
      pt.y;
}

void hbDockDragEnd(
   HB_DOCK_DRAG * pDrag )
{
   if( pDrag == NULL )
      return;

   pDrag->Dragging = FALSE;

   pDrag->hWndSource = NULL;

   pDrag->Guide = HB_GUIDE_NONE;

   SetRectEmpty(
      &pDrag->DragRect );
}

void hbDockDragCancel(
   HB_DOCK_DRAG * pDrag )
{
   if( pDrag == NULL )
      return;

   pDrag->Dragging = FALSE;

   pDrag->hWndSource = NULL;

   pDrag->Guide = HB_GUIDE_NONE;

   SetRectEmpty(
      &pDrag->DragRect );
}