#include "hbdockpanelstate.h"
#include "hbdockpanel.h"


void hbDockPanelSetState(
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_PANEL_STATE State )
{
   if( pPanel == NULL )
      return;

   pPanel->State = State;
}


HB_DOCK_PANEL_STATE hbDockPanelGetState(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return HB_PANEL_STATE_HIDDEN;

   return pPanel->State;
}