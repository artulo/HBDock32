#ifndef HBDOCKPANELFLAGS_H
#define HBDOCKPANELFLAGS_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetFlags(
   HB_DOCK_PANEL * pPanel,
   unsigned long Flags );

void hbDockPanelAddFlags(
   HB_DOCK_PANEL * pPanel,
   unsigned long Flags );

void hbDockPanelRemoveFlags(
   HB_DOCK_PANEL * pPanel,
   unsigned long Flags );

int hbDockPanelHasFlags(
   const HB_DOCK_PANEL * pPanel,
   unsigned long Flags );

#ifdef __cplusplus
}
#endif

#endif