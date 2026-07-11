#include "hbdockautohideslideengine.h"

void hbDockAutoHideSlideIn(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   pPane->Sliding = 1;
   pPane->SlideDirection = 1;
}

void hbDockAutoHideSlideOut(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   pPane->Sliding = 1;
   pPane->SlideDirection = -1;
}

void hbDockAutoHideStopSlide(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   pPane->Sliding = 0;
}

int hbDockAutoHideSlideRunning(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Sliding;
}