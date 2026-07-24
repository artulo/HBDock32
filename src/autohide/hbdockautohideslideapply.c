#include <windows.h>

#include "hbdockautohideslideapply.h"

void hbDockAutoHideApplySlide(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   RECT rc;

   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   rc = pAutoHide->VisibleRect;

   MoveWindow(
      pAutoHide->Panel->hWnd,
      rc.left,
      rc.top,
      rc.right - rc.left,
      rc.bottom - rc.top,
      TRUE );
}