#include <windows.h>

#include "hbdockfloatingcapture.h"

void hbDockFloatingSetCapture(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      SetCapture(
         pFrame->hWnd );
}

void hbDockFloatingReleaseCapture(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   HB_SYMBOL_UNUSED( pFrame );

   ReleaseCapture();
}

int hbDockFloatingHasCapture(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return 0;

   return GetCapture() ==
      pFrame->hWnd;
}