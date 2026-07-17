#include "hbdockautohidestate.h"

void hbDockAutoHideSetState(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   DWORD dwState )
{
   if( pPane != NULL )
      pPane->State = dwState;
}

DWORD hbDockAutoHideGetState(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->State;
}