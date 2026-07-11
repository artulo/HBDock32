#ifndef HBDOCKAUTOHIDEGEOMETRY_H
#define HBDOCKAUTOHIDEGEOMETRY_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideGetWindowRect(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   RECT * pRect );

BOOL hbDockAutoHideSetWindowRect(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   const RECT * pRect,
   BOOL bRepaint );

#ifdef __cplusplus
}
#endif

#endif