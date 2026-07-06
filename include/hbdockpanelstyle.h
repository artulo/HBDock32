#ifndef HBDOCKPANELSTYLE_H
#define HBDOCKPANELSTYLE_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetStyle(
   HB_DOCK_PANEL * pPanel,
   DWORD dwStyle );

void hbDockPanelSetExStyle(
   HB_DOCK_PANEL * pPanel,
   DWORD dwExStyle );

DWORD hbDockPanelGetStyle(
   const HB_DOCK_PANEL * pPanel );

DWORD hbDockPanelGetExStyle(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif