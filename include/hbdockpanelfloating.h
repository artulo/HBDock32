#ifndef HBDOCKPANELFLOATING_H
#define HBDOCKPANELFLOATING_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetFloating(
   HB_DOCK_PANEL * pPanel,
   int bFloating );

int hbDockPanelIsFloating(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif