#include <windows.h>

#include "hbdockautohidebuttonparent.h"

HWND hbDockAutoHideButtonGetParent(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return NULL;

   return GetParent(
      pButton->hWnd );
}

void hbDockAutoHideButtonSetParent(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   HWND hParent )
{
   if( pButton == NULL )
      return;

   SetParent(
      pButton->hWnd,
      hParent );
}