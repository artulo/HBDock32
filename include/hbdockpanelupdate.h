#ifndef HBDOCKPANELUPDATE_H
#define HBDOCKPANELUPDATE_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelBeginUpdate(
   HB_DOCK_PANEL * pPanel );

void hbDockPanelEndUpdate(
   HB_DOCK_PANEL * pPanel );

int hbDockPanelIsUpdating(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif