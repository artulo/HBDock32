#ifndef HBDOCKPANELRECT_H
#define HBDOCKPANELRECT_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetRect(
   HB_DOCK_PANEL * pPanel,
   const RECT * pRect );

void hbDockPanelGetRect(
   const HB_DOCK_PANEL * pPanel,
   RECT * pRect );

int hbDockPanelWidth(
   const HB_DOCK_PANEL * pPanel );

int hbDockPanelHeight(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif