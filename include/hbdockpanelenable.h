#ifndef HBDOCKPANELENABLE_H
#define HBDOCKPANELENABLE_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelEnable(
   HB_DOCK_PANEL * pPanel,
   int Enable );

int hbDockPanelIsEnabled(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif