#ifndef HBDOCKAUTOHIDEPLACEMENT_H
#define HBDOCKAUTOHIDEPLACEMENT_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideGetPlacement(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   WINDOWPLACEMENT * pPlacement );

BOOL hbDockAutoHideSetPlacement(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   const WINDOWPLACEMENT * pPlacement );

#ifdef __cplusplus
}
#endif

#endif