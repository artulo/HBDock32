#include <string.h>

#include "hbdockautohidestrip.h"

void hbDockAutoHideStripInit(
   HB_DOCK_AUTOHIDE_STRIP * pStrip )
{
   memset(
      pStrip,
      0,
      sizeof( HB_DOCK_AUTOHIDE_STRIP ) );

   hbDockArrayInit(
      &pStrip->Buttons );
}

void hbDockAutoHideStripDestroy(
   HB_DOCK_AUTOHIDE_STRIP * pStrip )
{
   if( pStrip == NULL )
      return;

   hbDockArrayDestroy(
      &pStrip->Buttons );
}