#include <windows.h>

#include "hbdockautohidechildren.h"

HWND hbDockAutoHideGetFirstChild(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return NULL;

   return GetWindow(
      pPane->hWnd,
      GW_CHILD );
}

HWND hbDockAutoHideGetNextSibling(
   HWND hWnd )
{
   return GetWindow(
      hWnd,
      GW_HWNDNEXT );
}

HWND hbDockAutoHideGetPreviousSibling(
   HWND hWnd )
{
   return GetWindow(
      hWnd,
      GW_HWNDPREV );
}