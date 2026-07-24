#ifndef HBDOCKAUTOHIDEPLACEMENT_H
#define HBDOCKAUTOHIDEPLACEMENT_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideGetPlacement(
   HB_DOCK_AUTOHIDE * pAutoHide,
   WINDOWPLACEMENT * pPlacement );

BOOL hbDockAutoHideSetPlacement(
   HB_DOCK_AUTOHIDE * pAutoHide,
   const WINDOWPLACEMENT * pPlacement );

#ifdef __cplusplus
}
#endif

#endif