#ifndef HBDOCKAUTOHIDEVISIBLE_H
#define HBDOCKAUTOHIDEVISIBLE_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideShowWindow(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideHideWindow(
   HB_DOCK_AUTOHIDE * pAutoHide );

BOOL hbDockAutoHideWindowVisible(
   HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif