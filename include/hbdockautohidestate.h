#ifndef HBDOCKAUTOHIDESTATE_H
#define HBDOCKAUTOHIDESTATE_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetState(
   HB_DOCK_AUTOHIDE * pAutoHide,
   DWORD dwState );

DWORD hbDockAutoHideGetState(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif