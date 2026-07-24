#include <windows.h>

#include "hbdockhost.h"
#include "hbdockmanagerlayout.h"

void hbDockHostResize(
   HB_DOCK_HOST * pHost )
{
   RECT rc;

   if( pHost == NULL )
      return;

   if( pHost->hWnd == NULL )
      return;

   GetClientRect(
      pHost->hWnd,
      &rc );

   if( pHost->pManager != NULL )
   {
      hbDockManagerUpdateLayout(
         pHost->pManager );
   }

   InvalidateRect(
      pHost->hWnd,
      &rc,
      TRUE );
}