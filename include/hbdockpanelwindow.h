#ifndef HBDOCKPANELWINDOW_H
#define HBDOCKPANELWINDOW_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelAttachWindow(
   HB_DOCK_PANEL * pPanel,
   HWND hWnd );

HWND hbDockPanelDetachWindow(
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif