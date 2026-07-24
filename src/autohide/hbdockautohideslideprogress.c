#include "hbdockautohideslideprogress.h"
 
double hbDockAutoHideSlideProgress(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0.0;

   if( pAutoHide->SlideSize == 0 )
      return 0.0;

   return ( double ) pAutoHide->SlidePosition /
          ( double ) pAutoHide->SlideSize;
}