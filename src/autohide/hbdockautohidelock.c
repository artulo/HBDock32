#include "hbdockautohidelock.h"

void hbDockAutoHideLock(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Locked = TRUE;
}

void hbDockAutoHideUnlock(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Locked = FALSE;
}

int hbDockAutoHideIsLocked(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return FALSE;

   return pPane->Locked;
}