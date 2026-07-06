#ifndef HBDOCKPANELACTIVATE_H
#define HBDOCKPANELACTIVATE_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelActivate(
   HB_DOCK_PANEL * pPanel );

void hbDockPanelDeactivate(
   HB_DOCK_PANEL * pPanel );

int hbDockPanelIsActive(
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif