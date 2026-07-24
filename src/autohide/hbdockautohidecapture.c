#include <windows.h>

#include "hbdockautohidecapture.h"

void hbDockAutoHideSetCapture(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SetCapture(
      pAutoHide->Panel->hWnd );
}

void hbDockAutoHideReleaseCapture( void )
{
   ReleaseCapture();
}

int hbDockAutoHideHasCapture(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   if( pAutoHide->Panel == NULL )
      return 0;

   return GetCapture() ==
      pAutoHide->Panel->hWnd;
}