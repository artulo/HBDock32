#ifndef HBDOCKPANELFLOATRECT_H
#define HBDOCKPANELFLOATRECT_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetFloatRect(
   HB_DOCK_PANEL * pPanel,
   const RECT * pRect );

void hbDockPanelGetFloatRect(
   const HB_DOCK_PANEL * pPanel,
   RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif