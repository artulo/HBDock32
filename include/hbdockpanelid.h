#ifndef HBDOCKPANELID_H
#define HBDOCKPANELID_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetId(
   HB_DOCK_PANEL * pPanel,
   unsigned int Id );

unsigned int hbDockPanelGetId(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif