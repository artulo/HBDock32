#ifndef HBDOCKAUTOHIDEPAINT_H
#define HBDOCKAUTOHIDEPAINT_H

#include <windows.h>

#include "hbdockautohidestrip.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideStripPaint(
   HB_DOCK_AUTOHIDE_STRIP * pStrip,
   HDC hDC );

#ifdef __cplusplus
}
#endif

#endif