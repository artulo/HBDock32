#include <windows.h>

#include "hbdockautohidemouse.h"

void hbDockAutoHideGetMousePos(
   POINT * pPoint )
{
   if( pPoint == NULL )
      return;

   GetCursorPos(
      pPoint );
}


int hbDockAutoHideMouseInside(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   RECT rc;
   POINT pt;

   if( pAutoHide == NULL )
      return 0;

   if( pAutoHide->Panel == NULL )
      return 0;

   if( pAutoHide->Panel->hWnd == NULL )
      return 0;

   GetCursorPos(
      &pt );

   GetWindowRect(
      pAutoHide->Panel->hWnd,
      &rc );

   return PtInRect(
      &rc,
      pt );
}