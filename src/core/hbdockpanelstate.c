#include "hbdockpanelstate.h"

void hbDockPanelSetState(
        HB_DOCK_PANEL * pPanel,
        HB_DOCK_PANEL_STATE State )
{
    if( pPanel )
        pPanel->State = (DWORD) State;
}

HB_DOCK_PANEL_STATE
hbDockPanelGetState(
        const HB_DOCK_PANEL * pPanel )
{
    if( pPanel == NULL )
        return HB_PANEL_STATE_HIDDEN;

    return (HB_DOCK_PANEL_STATE) pPanel->State;
}