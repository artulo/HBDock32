#include "hbdockautohidecontains.h"

int hbDockAutoHideContains(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   int i;

   if( pManager == NULL )
      return 0;

   for( i = 0; i < pManager->Panes.Count; ++i )
   {
      if( hbDockArrayGet(
             &pManager->Panes,
             i ) == pPane )
         return 1;
   }

   return 0;
}