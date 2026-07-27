#include <stdlib.h>

#include "hbdockautohideanimationadd.h"

int hbDockAutoHideAnimationAddPane(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager,
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pManager->Count >= pManager->Capacity )
   {
      int nCapacity =
         pManager->Capacity + 16;

      HB_DOCK_AUTOHIDE ** pNew =
         ( HB_DOCK_AUTOHIDE ** )
         realloc(
            pManager->pPanes,
            sizeof( HB_DOCK_AUTOHIDE * ) *
            nCapacity );

      if( pNew == NULL )
         return 0;

      pManager->pPanes = pNew;
      pManager->Capacity = nCapacity;
   }

   pManager->pPanes[
      pManager->Count++ ] = pAutoHide;

   return 1;
}