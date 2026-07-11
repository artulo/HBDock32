#include <windows.h>

#include "hbdockautohideredrawbutton.h"

void hbDockAutoHideRedrawButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   if( pButton->hWnd == NULL )
      return;

   RedrawWindow(
      pButton->hWnd,
      NULL,
      NULL,
      RDW_INVALIDATE |
      RDW_UPDATENOW |
      RDW_ALLCHILDREN );
}