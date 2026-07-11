#include "hbdockautohideremoveat.h"

int hbDockAutoHideRemoveAt(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   int nIndex )
{
   if( pManager == NULL )
      return 0;

   return hbDockArrayRemove(
      &pManager->Panes,
      nIndex );
}