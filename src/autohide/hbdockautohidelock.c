#include "hbdockautohidelock.h"

void hbDockAutoHideLock(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Locked = 1;
}

void hbDockAutoHideUnlock(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Locked = 0;
}

int hbDockAutoHideIsLocked(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Locked;
}