#include <windows.h>

#include "hbdockautohideposition.h"

void hbDockAutoHideGetPosition(
   HB_DOCK_AUTOHIDE * pAutoHide,
   POINT * pPoint )
{
   RECT rc;

   if( pAutoHide == NULL || pPoint == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   GetWindowRect(
      pAutoHide->Panel->hWnd,
      &rc );

   pPoint->x = rc.left;
   pPoint->y = rc.top;
}