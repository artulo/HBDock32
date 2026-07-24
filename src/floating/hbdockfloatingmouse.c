#include <windows.h>

#include "hbdockfloatingmouse.h"
#include "hbApi.h"
void hbDockFloatingGetMousePosition(
   HB_DOCK_FLOATING_FRAME * pFrame,
   POINT * pPoint )
{
   HB_SYMBOL_UNUSED( pFrame );

   if( pPoint == NULL )
      return;

   GetCursorPos(
      pPoint );
}

int hbDockFloatingMouseInside(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   POINT pt;
   RECT rc;

   if( pFrame == NULL )
      return 0;

   if( pFrame->hWnd == NULL )
      return 0;

   GetCursorPos(
      &pt );

   GetWindowRect(
      pFrame->hWnd,
      &rc );

   return PtInRect(
      &rc,
      pt );
}