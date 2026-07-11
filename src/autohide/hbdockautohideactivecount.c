#include "hbdockautohideactivecount.h"

int hbDockAutoHideAnimationCount(
   const HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager )
{
   if( pManager == NULL )
      return 0;

   return pManager->Count;
}