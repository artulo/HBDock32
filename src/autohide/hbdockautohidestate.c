#include "hbdockautohidestate.h"

void hbDockAutoHideSetState(
   HB_DOCK_AUTOHIDE * pAutoHide,
   DWORD dwState )
{
   if( pAutoHide != NULL )
      pAutoHide->State = dwState;
}


DWORD hbDockAutoHideGetState(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->State;
}