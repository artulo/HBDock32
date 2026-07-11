#include <windows.h>

#include "hbdockautohidecapture.h"

void hbDockAutoHideSetCapture(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   SetCapture(
      pPane->hWnd );
}

void hbDockAutoHideReleaseCapture( void )
{
   ReleaseCapture();
}

int hbDockAutoHideHasCapture(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return GetCapture() ==
      pPane->hWnd;
}