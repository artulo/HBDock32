#include "hbdockautohideslideengine.h"

void hbDockAutoHideSlideIn(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->Sliding = 1;
   pAutoHide->SlideDirection = 1;
}


void hbDockAutoHideSlideOut(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->Sliding = 1;
   pAutoHide->SlideDirection = -1;
}


void hbDockAutoHideStopSlide(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->Sliding = 0;
}


int hbDockAutoHideSlideRunning(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->Sliding;
}