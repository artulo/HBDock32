#include "hbdockautohideanimationqueue.h"

int hbDockAutoHideAnimationIsQueued(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager,
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   int i;

   if( pManager == NULL )
      return 0;

   for( i = 0; i < pManager->Count; ++i )
   {
      if( pManager->pPanes[ i ] == pPane )
         return 1;
   }

   return 0;
}

void hbDockAutoHideAnimationClear(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   pManager->Count = 0;
}