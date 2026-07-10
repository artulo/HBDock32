#include "hbdockautohidecount.h"

int hbDockAutoHidePaneCount(
   const HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return 0;

   return pManager->Panes.Count;
}