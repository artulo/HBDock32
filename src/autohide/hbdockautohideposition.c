#include <windows.h>

#include "hbdockautohideposition.h"

void hbDockAutoHideGetPosition(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   POINT * pPoint )
{
   RECT rc;

   if( pPane == NULL || pPoint == NULL )
      return;

   GetWindowRect(
      pPane->hWnd,
      &rc );

   pPoint->x = rc.left;
   pPoint->y = rc.top;
}