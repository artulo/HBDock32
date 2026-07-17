#include "hbdockautohideanimationpause.h"

void hbDockAutoHideAnimationPause(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager )
{
   if( pManager )
      pManager->Paused = TRUE;
}

void hbDockAutoHideAnimationResume(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager )
{
   if( pManager )
      pManager->Paused = FALSE;
}