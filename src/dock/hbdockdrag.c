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
}

void hbDockDragBegin(
   HB_DOCK_DRAG * pDrag,
   HWND hWnd,
   POINT pt )
{
   if( pDrag == NULL )
      return;

   pDrag->Active = 1;
   pDrag->hWndSource = hWnd;
   pDrag->StartPoint = pt;
   pDrag->CurrentPoint = pt;

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

   if( !pDrag->Active )
      return;

   pDrag->CurrentPoint = pt;

   pDrag->DragRect.right  = pt.x;
   pDrag->DragRect.bottom = pt.y;
}

void hbDockDragEnd(
   HB_DOCK_DRAG * pDrag )
{
   if( pDrag == NULL )
      return;

   pDrag->Active = 0;
   pDrag->hWndSource = NULL;
}