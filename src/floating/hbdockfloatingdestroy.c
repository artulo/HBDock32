#include <windows.h>

#include "hbdockfloatingdestroy.h"

void hbDockFloatingDestroyWindow(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
   {
      DestroyWindow(
         pFrame->hWnd );

      pFrame->hWnd = NULL;
   }
}