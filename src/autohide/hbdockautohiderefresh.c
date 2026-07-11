#include <windows.h>

#include "hbdockautohiderefresh.h"

void hbDockAutoHideRefresh(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   if( pPane->hWnd == NULL )
      return;

   InvalidateRect(
      pPane->hWnd,
      NULL,
      TRUE );

   UpdateWindow(
      pPane->hWnd );
}