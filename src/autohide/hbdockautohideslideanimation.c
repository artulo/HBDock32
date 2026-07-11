#include "hbdockautohideslideanimation.h"

void hbDockAutoHideAnimationStep(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   if( !pPane->Sliding )
      return;

   pPane->SlidePosition +=
      pPane->SlideDirection *
      pPane->SlideStep;
}