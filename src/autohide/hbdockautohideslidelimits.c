#include "hbdockautohideslidelimits.h"

void hbDockAutoHideNormalizeSlide(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   if( pPane->SlidePosition < 0 )
      pPane->SlidePosition = 0;

   if( pPane->SlidePosition > pPane->SlideSize )
      pPane->SlidePosition = pPane->SlideSize;
}