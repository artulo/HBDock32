#include <windows.h>

#include "hbdockfloatingposition.h"

void hbDockFloatingSetPosition(
   HB_DOCK_FLOATING_FRAME * pFrame,
   const RECT * pRect )
{
   if( pFrame == NULL )
      return;

   if( pRect == NULL )
      return;

   pFrame->Rect = *pRect;

   if( pFrame->hWnd != NULL )
      MoveWindow(
         pFrame->hWnd,
         pRect->left,
         pRect->top,
         pRect->right - pRect->left,
         pRect->bottom - pRect->top,
         TRUE );
}

void hbDockFloatingGetPosition(
   const HB_DOCK_FLOATING_FRAME * pFrame,
   RECT * pRect )
{
   if( pFrame == NULL )
      return;

   if( pRect == NULL )
      return;

   *pRect = pFrame->Rect;
}