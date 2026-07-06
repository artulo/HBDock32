#ifndef HBDOCKPANELMODIFIED_H
#define HBDOCKPANELMODIFIED_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetModified(
   HB_DOCK_PANEL * pPanel,
   int bModified );

int hbDockPanelIsModified(
   const HB_DOCK_PANEL * pPanel );

void hbDockPanelClearModified(
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif