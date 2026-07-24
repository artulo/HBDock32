#include "hbdockautohideslidelimits.h"

void hbDockAutoHideNormalizeSlide(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->SlidePosition < 0 )
      pAutoHide->SlidePosition = 0;

   if( pAutoHide->SlidePosition > pAutoHide->SlideSize )
      pAutoHide->SlidePosition = pAutoHide->SlideSize;
}