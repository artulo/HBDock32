#ifndef HBDOCKPANELMARGIN_H
#define HBDOCKPANELMARGIN_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetMargin(
   HB_DOCK_PANEL * pPanel,
   int Left,
   int Top,
   int Right,
   int Bottom );

void hbDockPanelGetMargin(
   const HB_DOCK_PANEL * pPanel,
   RECT * pMargin );

#ifdef __cplusplus
}
#endif

#endif