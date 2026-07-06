#ifndef HBDOCKPANELSTATE_H
#define HBDOCKPANELSTATE_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_DOCK_PANEL_STATE_DOCKED = 0,
   HB_DOCK_PANEL_STATE_FLOATING,
   HB_DOCK_PANEL_STATE_AUTOHIDE,
   HB_DOCK_PANEL_STATE_HIDDEN

} HB_DOCK_PANEL_STATE;

void hbDockPanelSetState(
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_PANEL_STATE State );

HB_DOCK_PANEL_STATE hbDockPanelGetState(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif