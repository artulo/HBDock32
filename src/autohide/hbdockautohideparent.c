#include <windows.h>

#include "hbdockautohideparent.h"

HWND hbDockAutoHideGetParent(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return NULL;

   return GetParent(
      pPane->hWnd );
}

void hbDockAutoHideSetParent(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HWND hParent )
{
   if( pPane == NULL )
      return;

   SetParent(
      pPane->hWnd,
      hParent );
}