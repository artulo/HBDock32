#include <windows.h>

#include "hbdockautohidebuttonrect.h"

BOOL hbDockAutoHideButtonGetRect(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   RECT * pRect )
{
   if( pButton == NULL || pRect == NULL )
      return FALSE;

   return GetWindowRect(
      pButton->hWnd,
      pRect );
}

BOOL hbDockAutoHideButtonGetClientRect(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   RECT * pRect )
{
   if( pButton == NULL || pRect == NULL )
      return FALSE;

   return GetClientRect(
      pButton->hWnd,
      pRect );
}