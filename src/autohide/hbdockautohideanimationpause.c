#include "hbdockautohideanimationpause.h"

void hbDockAutoHideAnimationPause(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   pManager->Paused = 1;
}

void hbDockAutoHideAnimationResume(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   pManager->Paused = 0;
}