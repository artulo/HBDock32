#include <windows.h>

#include "hbdockfloatingmove.h"

void hbDockFloatingMove(
   HB_DOCK_FLOATING_FRAME * pFrame,
   int x,
   int y )
{
   if( pFrame == NULL )
      return;

   pFrame->Rect.right +=
      x - pFrame->Rect.left;

   pFrame->Rect.bottom +=
      y - pFrame->Rect.top;

   pFrame->Rect.left = x;
   pFrame->Rect.top = y;

   if( pFrame->hWnd != NULL )
      MoveWindow(
         pFrame->hWnd,
         pFrame->Rect.left,
         pFrame->Rect.top,
         pFrame->Rect.right -
            pFrame->Rect.left,
         pFrame->Rect.bottom -
            pFrame->Rect.top,
         TRUE );
}

void hbDockFloatingResize(
   HB_DOCK_FLOATING_FRAME * pFrame,
   int cx,
   int cy )
{
   if( pFrame == NULL )
      return;

   pFrame->Rect.right =
      pFrame->Rect.left + cx;

   pFrame->Rect.bottom =
      pFrame->Rect.top + cy;

   if( pFrame->hWnd != NULL )
      MoveWindow(
         pFrame->hWnd,
         pFrame->Rect.left,
         pFrame->Rect.top,
         cx,
         cy,
         TRUE );
}