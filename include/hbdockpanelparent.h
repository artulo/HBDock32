#ifndef HBDOCKPANELPARENT_H
#define HBDOCKPANELPARENT_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetParent(
   HB_DOCK_PANEL * pPanel,
   HWND hParent );

HWND hbDockPanelGetParent(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif