#ifndef HBDOCKAUTOHIDEPARENT_H
#define HBDOCKAUTOHIDEPARENT_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideGetParent(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideSetParent(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HWND hParent );

#ifdef __cplusplus
}
#endif

#endif