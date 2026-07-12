#ifndef HBDOCKPANELADD_H
#define HBDOCKPANELADD_H

#include "hbdockpanelregistry.h"

BOOL hbDockPanelAdd(
      HB_DOCK_PANEL_REGISTRY * pRegistry,
      HWND hWnd,
      LPCTSTR pszName,
      LPCTSTR pszCaption );

#endif