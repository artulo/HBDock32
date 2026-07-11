#include "hbdockautohideanimation.h"

void hbDockAutoHideSetAnimation(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int bEnable )
{
   if( pPane != NULL )
      pPane->Animation = bEnable;
}

int hbDockAutoHideAnimationEnabled(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Animation;
}