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
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   RECT rc;
   POINT pt;

   if( pPane == NULL )
      return 0;

   GetCursorPos(
      &pt );

   GetWindowRect(
      pPane->hWnd,
      &rc );

   return PtInRect(
      &rc,
      pt );
}