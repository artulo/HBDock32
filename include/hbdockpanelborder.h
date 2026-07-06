#ifndef HBDOCKPANELBORDER_H
#define HBDOCKPANELBORDER_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetBorder(
   HB_DOCK_PANEL * pPanel,
   int nBorder );

int hbDockPanelGetBorder(
   const HB_DOCK_PANEL * pPanel );

RECT hbDockPanelGetClientRect(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif