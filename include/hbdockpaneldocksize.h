#ifndef HBDOCKPANELDOCKSIZE_H
#define HBDOCKPANELDOCKSIZE_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetDockSize(
   HB_DOCK_PANEL * pPanel,
   int cx,
   int cy );

void hbDockPanelGetDockSize(
   const HB_DOCK_PANEL * pPanel,
   SIZE * pSize );

#ifdef __cplusplus
}
#endif

#endif