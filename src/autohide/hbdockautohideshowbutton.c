#include <windows.h>

#include "hbdockautohideshowbutton.h"

void hbDockAutoHideShowButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   ShowWindow(
      pButton->hWnd,
      SW_SHOW );
}

void hbDockAutoHideHideButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   ShowWindow(
      pButton->hWnd,
      SW_HIDE );
}