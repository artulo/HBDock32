#include <windows.h>

#include "hbdockautohideowner.h"

HWND hbDockAutoHideGetOwner(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return NULL;

   return GetWindow(
      pPane->hWnd,
      GW_OWNER );
}

void hbDockAutoHideSetOwner(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HWND hOwner )
{
   if( pPane == NULL )
      return;

   SetWindowLong(
      pPane->hWnd,
      GWL_HWNDPARENT,
      ( LONG ) hOwner );
}