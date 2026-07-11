#include <windows.h>

#include "hbdockautohideupdatebutton.h"

void hbDockAutoHideUpdateButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   if( pButton->hWnd == NULL )
      return;

   UpdateWindow(
      pButton->hWnd );
}