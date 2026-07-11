#include <stdlib.h>
#include <string.h>

#include "hbdockautohideanimationmanager.h"

void hbDockAutoHideAnimationManagerInit(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager )
{
   memset(
      pManager,
      0,
      sizeof(
         HB_DOCK_AUTOHIDE_ANIMATION_MANAGER ) );

   pManager->Interval = 15;
}

void hbDockAutoHideAnimationManagerDone(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager )
{
   if( pManager->pPanes )
      free(
         pManager->pPanes );

   memset(
      pManager,
      0,
      sizeof(
         HB_DOCK_AUTOHIDE_ANIMATION_MANAGER ) );
}