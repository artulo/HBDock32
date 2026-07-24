#include <windows.h>

#include "hbdockautohidechildren.h"

HWND hbDockAutoHideGetFirstChild(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return NULL;

   if( pAutoHide->Panel == NULL )
      return NULL;

   if( pAutoHide->Panel->hWnd == NULL )
      return NULL;

   return GetWindow(
      pAutoHide->Panel->hWnd,
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