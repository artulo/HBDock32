#include <windows.h>

#include "hbdockautohidebuttoncapture.h"

void hbDockAutoHideButtonSetCapture(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   SetCapture(
      pButton->hWnd );
}

void hbDockAutoHideButtonReleaseCapture( void )
{
   ReleaseCapture();
}

int hbDockAutoHideButtonHasCapture(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return GetCapture() ==
      pButton->hWnd;
}