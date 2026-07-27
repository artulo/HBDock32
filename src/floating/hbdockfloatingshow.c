#include <windows.h>

#include "hbdockfloatingshow.h"

void hbDockFloatingFrameShow(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      ShowWindow(
         pFrame->hWnd,
         SW_SHOW );
}

void hbDockFloatingHide(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      ShowWindow(
         pFrame->hWnd,
         SW_HIDE );
}