#ifndef HBDOCKPANELSIZE_H
#define HBDOCKPANELSIZE_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetMinSize(
   HB_DOCK_PANEL * pPanel,
   int cx,
   int cy );

void hbDockPanelSetMaxSize(
   HB_DOCK_PANEL * pPanel,
   int cx,
   int cy );

void hbDockPanelGetMinSize(
   const HB_DOCK_PANEL * pPanel,
   SIZE * pSize );

void hbDockPanelGetMaxSize(
   const HB_DOCK_PANEL * pPanel,
   SIZE * pSize );

#ifdef __cplusplus
}
#endif

#endif