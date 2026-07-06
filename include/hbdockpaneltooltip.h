#ifndef HBDOCKPANELTOOLTIP_H
#define HBDOCKPANELTOOLTIP_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetToolTip(
   HB_DOCK_PANEL * pPanel,
   HWND hToolTip );

HWND hbDockPanelGetToolTip(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif