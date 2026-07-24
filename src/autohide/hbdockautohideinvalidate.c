#include <windows.h>

#include "hbdockautohideinvalidate.h"

void hbDockAutoHideInvalidate(
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
}