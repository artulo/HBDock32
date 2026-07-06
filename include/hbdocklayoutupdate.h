#ifndef HBDOCKLAYOUTUPDATE_H
#define HBDOCKLAYOUTUPDATE_H

#include <windows.h>

#include "hbdocklayoutengine.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockLayoutUpdate(
   HB_DOCK_LAYOUT_ENGINE * pEngine,
   HWND hWnd );

#ifdef __cplusplus
}
#endif

#endif