#include "hbdockautohideacceleration.h"

void hbDockAutoHideSetAcceleration(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nAccel )
{
   if( pPane == NULL )
      return;

   pPane->SlideAcceleration = nAccel;
}

int hbDockAutoHideGetAcceleration(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->SlideAcceleration;
}