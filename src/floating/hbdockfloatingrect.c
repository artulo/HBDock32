#include <windows.h>

#include "hbdockfloatingrect.h"

void hbDockFloatingGetRect(
   HB_DOCK_FLOATING_FRAME * pFrame,
   RECT * pRect )
{
   if( pFrame == NULL )
      return;

   if( pRect == NULL )
      return;

   if( pFrame->hWnd != NULL )
      GetWindowRect(
         pFrame->hWnd,
         pRect );
   else
      *pRect = pFrame->Rect;
}

void hbDockFloatingSetRect(
   HB_DOCK_FLOATING_FRAME * pFrame,
   const RECT * pRect )
{
   if( pFrame == NULL )
      return;

   if( pRect == NULL )
      return;

   pFrame->Rect = *pRect;

   if( pFrame->hWnd != NULL )
   {
      MoveWindow(
         pFrame->hWnd,
         pRect->left,
         pRect->top,
         pRect->right - pRect->left,
         pRect->bottom - pRect->top,
         TRUE );
   }
}