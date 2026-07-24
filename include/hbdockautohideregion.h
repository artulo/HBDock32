#ifndef HBDOCKAUTOHIDEREGION_H
#define HBDOCKAUTOHIDEREGION_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetRegion(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HRGN hRegion,
   BOOL bRedraw );

void hbDockAutoHideClearRegion(
   HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif