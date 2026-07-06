#ifndef HBDOCKPANELZORDER_H
#define HBDOCKPANELZORDER_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelBringToFront(
   HB_DOCK_PANEL * pPanel );

void hbDockPanelSendToBack(
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif