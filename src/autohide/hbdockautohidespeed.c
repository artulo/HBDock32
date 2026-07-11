#include "hbdockautohidespeed.h"

void hbDockAutoHideSetSlideSpeed(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nSpeed )
{
   if( pPane == NULL )
      return;

   if( nSpeed < 1 )
      nSpeed = 1;

   pPane->SlideStep = nSpeed;
}

int hbDockAutoHideGetSlideSpeed(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->SlideStep;
}