#ifndef HBDOCKPANELMOVE_H
#define HBDOCKPANELMOVE_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelMoveWindow(
   HB_DOCK_PANEL * pPanel );

void hbDockPanelResize(
   HB_DOCK_PANEL * pPanel,
   int Width,
   int Height );

#ifdef __cplusplus
}
#endif

#endif