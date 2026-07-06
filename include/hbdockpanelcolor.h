#ifndef HBDOCKPANELCOLOR_H
#define HBDOCKPANELCOLOR_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetBkColor(
   HB_DOCK_PANEL * pPanel,
   COLORREF Color );

void hbDockPanelSetTextColor(
   HB_DOCK_PANEL * pPanel,
   COLORREF Color );

COLORREF hbDockPanelGetBkColor(
   const HB_DOCK_PANEL * pPanel );

COLORREF hbDockPanelGetTextColor(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif