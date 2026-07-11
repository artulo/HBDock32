#include "hbdockautohideanimationtick.h"
#include "hbdockautohideslideupdate.h"

void hbDockAutoHideAnimationTick(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager )
{
   int i;

   for( i = 0; i < pManager->Count; ++i )
   {
      hbDockAutoHideUpdateSlide(
         pManager->pPanes[ i ] );
   }
}