#include <windows.h>

#include "hbdockautohidewindowid.h"

int hbDockAutoHideGetWindowId(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return GetWindowLong(
      pPane->hWnd,
      GWL_ID );
}

void hbDockAutoHideSetWindowId(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nId )
{
   if( pPane == NULL )
      return;

   SetWindowLong(
      pPane->hWnd,
      GWL_ID,
      ( LONG ) nId );
}