#include <windows.h>

#include "hbdockfloatingupdate.h"

void hbDockFloatingUpdate(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      UpdateWindow(
         pFrame->hWnd );
}

void hbDockFloatingRedraw(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      RedrawWindow(
         pFrame->hWnd,
         NULL,
         NULL,
         RDW_INVALIDATE |
         RDW_UPDATENOW |
         RDW_FRAME );
}