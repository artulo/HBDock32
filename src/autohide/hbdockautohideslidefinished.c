#include "hbdockautohideslidefinished.h"

int hbDockAutoHideSlideFinished(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 1;

   if( pAutoHide->SlideDirection > 0 )
      return pAutoHide->SlidePosition >= pAutoHide->SlideSize;

   return pAutoHide->SlidePosition <= 0;
}