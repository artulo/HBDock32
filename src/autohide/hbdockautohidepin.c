#include "hbdockautohidepin.h"

void hbDockAutoHidePin(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Pinned = 1;
}

void hbDockAutoHideUnpin(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Pinned = 0;
}

int hbDockAutoHideIsPinned(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Pinned;
}