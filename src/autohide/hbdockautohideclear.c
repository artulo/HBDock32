#include "hbdockautohideclear.h"

void hbDockAutoHideClear(
   HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   while( pManager->Panes.Count > 0 )
   {
      hbDockArrayRemove(
         &pManager->Panes,
         0 );
   }
}