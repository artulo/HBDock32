#include "hbdockautohidescheduler.h"

#include "hbdockautohideslideanimation.h"

void hbDockAutoHideSchedulerTick(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   hbDockAutoHideAnimationStep(
      pAutoHide );
}