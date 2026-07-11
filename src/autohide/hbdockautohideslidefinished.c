#include "hbdockautohideslidefinished.h"

int hbDockAutoHideSlideFinished(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 1;

   if( pPane->SlideDirection > 0 )
      return pPane->SlidePosition >= pPane->SlideSize;

   return pPane->SlidePosition <= 0;
}