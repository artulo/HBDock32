#include <windows.h>

#include "hbdockautohidebuttonowner.h"

HWND hbDockAutoHideButtonGetOwner(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return NULL;

   return GetWindow(
      pButton->hWnd,
      GW_OWNER );
}