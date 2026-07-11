#include "hbdockautohideslideprogress.h"

double hbDockAutoHideSlideProgress(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0.0;

   if( pPane->SlideSize == 0 )
      return 0.0;

   return ( double ) pPane->SlidePosition /
          ( double ) pPane->SlideSize;
}