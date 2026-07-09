#include <windows.h>

#include "hbdockfloatingvalidate.h"

int hbDockFloatingIsValid(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return 0;

   if( pFrame->hWnd == NULL )
      return 0;

   return IsWindow(
      pFrame->hWnd );
}