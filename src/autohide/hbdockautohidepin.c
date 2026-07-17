#include "hbdockautohidepin.h"

void hbDockAutoHidePin(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Pinned = TRUE;
}

void hbDockAutoHideUnpin(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Pinned = FALSE;
}

int hbDockAutoHideIsPinned(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return FALSE;

   return pPane->Pinned;
}