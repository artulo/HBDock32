#ifndef HBDOCKPANELTAG_H
#define HBDOCKPANELTAG_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetTag(
   HB_DOCK_PANEL * pPanel,
   long lTag );

long hbDockPanelGetTag(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif