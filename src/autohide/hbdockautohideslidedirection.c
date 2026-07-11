#include "hbdockautohideslidedirection.h"

void hbDockAutoHideSetDirection(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nDirection )
{
   if( pPane == NULL )
      return;

   pPane->SlideDirection = nDirection;
}

int hbDockAutoHideGetDirection(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->SlideDirection;
}