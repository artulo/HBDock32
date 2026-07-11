#include <windows.h>

#include "hbdockautohidebuttonwindowid.h"

int hbDockAutoHideButtonGetWindowId(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return GetWindowLong(
      pButton->hWnd,
      GWL_ID );
}

void hbDockAutoHideButtonSetWindowId(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   int nId )
{
   if( pButton == NULL )
      return;

   SetWindowLong(
      pButton->hWnd,
      GWL_ID,
      ( LONG ) nId );
}