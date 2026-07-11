#include "hbdockautohideanimationremove.h"

void hbDockAutoHideAnimationRemovePane(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager,
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   int i;

   for( i = 0; i < pManager->Count; ++i )
   {
      if( pManager->pPanes[ i ] == pPane )
      {
         int j;

         for( j = i; j < pManager->Count - 1; ++j )
            pManager->pPanes[ j ] =
               pManager->pPanes[ j + 1 ];

         --pManager->Count;
         break;
      }
   }
}