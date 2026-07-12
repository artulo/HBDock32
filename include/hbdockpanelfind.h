#ifndef HBDOCKPANELFIND_H
#define HBDOCKPANELFIND_H

#include "hbdockpanelregistry.h"

HB_DOCK_PANEL *
hbDockPanelFindName(
      HB_DOCK_PANEL_REGISTRY * pRegistry,
      LPCTSTR pszName );

HB_DOCK_PANEL *
hbDockPanelFindHWND(
      HB_DOCK_PANEL_REGISTRY * pRegistry,
      HWND hWnd );

#endif