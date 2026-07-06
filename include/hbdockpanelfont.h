#ifndef HBDOCKPANELFONT_H
#define HBDOCKPANELFONT_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetFont(
   HB_DOCK_PANEL * pPanel,
   HFONT hFont );

HFONT hbDockPanelGetFont(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif