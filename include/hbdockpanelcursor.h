#ifndef HBDOCKPANELCURSOR_H
#define HBDOCKPANELCURSOR_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetCursor(
   HB_DOCK_PANEL * pPanel,
   HCURSOR hCursor );

HCURSOR hbDockPanelGetCursor(
   const HB_DOCK_PANEL * pPanel );

void hbDockPanelApplyCursor(
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif