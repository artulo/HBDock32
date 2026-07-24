#include <windows.h>

#include "hbdockhost.h"

void hbDockHostInvalidate(
   HB_DOCK_HOST * pHost )
{
   if( pHost == NULL )
      return;

   if( pHost->hWnd == NULL )
      return;

   InvalidateRect(
      pHost->hWnd,
      NULL,
      TRUE );

   UpdateWindow(
      pHost->hWnd );
}