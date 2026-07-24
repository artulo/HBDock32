#include "hbdockautohidepin.h"

void hbDockAutoHidePin(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Pinned = TRUE;
}

void hbDockAutoHideUnpin(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Pinned = FALSE;
}

int hbDockAutoHideIsPinned(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return FALSE;

   return pAutoHide->Pinned;
}