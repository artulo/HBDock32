#include "hbdockautohideacceleration.h"

void hbDockAutoHideSetAcceleration(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nAccel )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->SlideAcceleration = nAccel;
}

int hbDockAutoHideGetAcceleration(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->SlideAcceleration;
}