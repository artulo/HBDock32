#include <windows.h>

#include "hbdockautohidebuttonchildren.h"

HWND hbDockAutoHideButtonGetFirstChild(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return NULL;

   return GetWindow(
      pButton->hWnd,
      GW_CHILD );
}

HWND hbDockAutoHideButtonGetNextSibling(
   HWND hWnd )
{
   return GetWindow(
      hWnd,
      GW_HWNDNEXT );
}

HWND hbDockAutoHideButtonGetPreviousSibling(
   HWND hWnd )
{
   return GetWindow(
      hWnd,
      GW_HWNDPREV );
}