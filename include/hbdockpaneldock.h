#ifndef HBDOCKPANELDOCK_H
#define HBDOCKPANELDOCK_H

#include "hbdockpanel.h"
#include "hbdockdocksite.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetDockSite(
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_SITE Site );

HB_DOCK_SITE hbDockPanelGetDockSite(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif