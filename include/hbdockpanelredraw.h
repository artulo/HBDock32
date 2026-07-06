#ifndef HBDOCKPANELREDRAW_H
#define HBDOCKPANELREDRAW_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelLockRedraw(
   HB_DOCK_PANEL * pPanel );

void hbDockPanelUnlockRedraw(
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif