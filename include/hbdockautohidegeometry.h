#ifndef HBDOCKAUTOHIDEGEOMETRY_H
#define HBDOCKAUTOHIDEGEOMETRY_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideGetWindowRect(
   HB_DOCK_AUTOHIDE * pAutoHide,
   RECT * pRect );

BOOL hbDockAutoHideSetWindowRect(
   HB_DOCK_AUTOHIDE * pAutoHide,
   const RECT * pRect,
   BOOL bRepaint );

#ifdef __cplusplus
}
#endif

#endif