#ifndef HBDOCKPANELPADDING_H
#define HBDOCKPANELPADDING_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetPadding(
   HB_DOCK_PANEL * pPanel,
   int Left,
   int Top,
   int Right,
   int Bottom );

void hbDockPanelGetPadding(
   const HB_DOCK_PANEL * pPanel,
   RECT * pPadding );

#ifdef __cplusplus
}
#endif

#endif