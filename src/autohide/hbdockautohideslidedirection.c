#include "hbdockautohideslidedirection.h"

void hbDockAutoHideSetDirection(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nDirection )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->SlideDirection = nDirection;
}

int hbDockAutoHideGetDirection(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->SlideDirection;
}