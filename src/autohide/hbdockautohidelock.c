#include "hbdockautohidelock.h"

void hbDockAutoHideLock(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Locked = TRUE;
}


void hbDockAutoHideUnlock(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Locked = FALSE;
}


int hbDockAutoHideIsLocked(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return FALSE;

   return pAutoHide->Locked;
}