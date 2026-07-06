#ifndef HBDOCKRENDER_H
#define HBDOCKRENDER_H

#include <windows.h>

#include "hbdocktheme.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockRenderPanel(
   HDC hDC,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_THEME * pTheme );

#ifdef __cplusplus
}
#endif

#endif