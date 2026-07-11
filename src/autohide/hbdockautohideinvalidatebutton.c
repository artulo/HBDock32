#include <windows.h>

#include "hbdockautohideinvalidatebutton.h"

void hbDockAutoHideInvalidateButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   if( pButton->hWnd == NULL )
      return;

   InvalidateRect(
      pButton->hWnd,
      NULL,
      TRUE );
}