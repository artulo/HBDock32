#include "hbdockautohidedelay.h"


void hbDockAutoHideSetDelay(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT nDelay )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->SlideSpeed = (int)nDelay;
}


UINT hbDockAutoHideGetDelay(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return (UINT)pAutoHide->SlideSpeed;
}