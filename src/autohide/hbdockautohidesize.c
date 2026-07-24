#include <windows.h>

#include "hbdockautohidesize.h"

void hbDockAutoHideGetSize(
   HB_DOCK_AUTOHIDE * pAutoHide,
   SIZE * pSize )
{
   RECT rc;

   if( pAutoHide == NULL || pSize == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   GetWindowRect(
      pAutoHide->Panel->hWnd,
      &rc );

   pSize->cx = rc.right - rc.left;
   pSize->cy = rc.bottom - rc.top;
}