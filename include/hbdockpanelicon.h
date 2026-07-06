#ifndef HBDOCKPANELICON_H
#define HBDOCKPANELICON_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetIcon(
   HB_DOCK_PANEL * pPanel,
   HICON hIcon );

HICON hbDockPanelGetIcon(
   const HB_DOCK_PANEL * pPanel );

void hbDockPanelApplyIcon(
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif