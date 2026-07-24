#include "hbdockautohidespeed.h"

void hbDockAutoHideSetSlideSpeed(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nSpeed )
{
   if( pAutoHide == NULL )
      return;

   if( nSpeed < 1 )
      nSpeed = 1;

   pAutoHide->SlideStep = nSpeed;
}


int hbDockAutoHideGetSlideSpeed(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->SlideStep;
}