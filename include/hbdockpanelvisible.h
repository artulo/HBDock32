#ifndef HBDOCKPANELVISIBLE_H
#define HBDOCKPANELVISIBLE_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelShow(
   HB_DOCK_PANEL * pPanel );

void hbDockPanelHide(
   HB_DOCK_PANEL * pPanel );

int hbDockPanelIsVisible(
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif