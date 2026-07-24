#include "hbdockautohideslideanimation.h"

void hbDockAutoHideAnimationStep(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( !pAutoHide->Sliding )
      return;

   pAutoHide->SlidePosition +=
      pAutoHide->SlideDirection *
      pAutoHide->SlideStep;
}