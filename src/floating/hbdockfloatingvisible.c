#include <windows.h>

#include "hbdockfloatingvisible.h"

int hbDockFloatingIsVisible(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return 0;

   if( pFrame->hWnd == NULL )
      return 0;

   return IsWindowVisible(
      pFrame->hWnd );
}