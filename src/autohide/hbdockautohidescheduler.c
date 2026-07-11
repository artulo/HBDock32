#include "hbdockautohidescheduler.h"

#include "hbdockautohideslideanimation.h"

void hbDockAutoHideSchedulerTick(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   hbDockAutoHideAnimationStep(
      pPane );
}