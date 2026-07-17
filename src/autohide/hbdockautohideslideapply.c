#include <windows.h>

#include "hbdockautohideslideapply.h"

void hbDockAutoHideApplySlide(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   RECT rc;

   if( pPane == NULL )
      return;

   if( pPane->hWnd == NULL )
      return;

   rc = pPane->WindowRect;

   MoveWindow(
      pPane->hWnd,
      rc.left,
      rc.top,
      rc.right - rc.left,
      rc.bottom - rc.top,
      TRUE );
}