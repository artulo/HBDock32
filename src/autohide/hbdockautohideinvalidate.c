#include <windows.h>

#include "hbdockautohideinvalidate.h"

void hbDockAutoHideInvalidate(
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
}