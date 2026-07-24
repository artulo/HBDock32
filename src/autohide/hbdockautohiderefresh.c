#include <windows.h>

#include "hbdockautohiderefresh.h"

void hbDockAutoHideRefresh(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   InvalidateRect(
      pAutoHide->Panel->hWnd,
      NULL,
      TRUE );

   UpdateWindow(
      pAutoHide->Panel->hWnd );
}