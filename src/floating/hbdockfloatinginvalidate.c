#include <windows.h>

#include "hbdockfloatinginvalidate.h"

void hbDockFloatingInvalidate(
   HB_DOCK_FLOATING_FRAME * pFrame,
   int bErase )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
   {
      InvalidateRect(
         pFrame->hWnd,
         NULL,
         bErase );
   }
}