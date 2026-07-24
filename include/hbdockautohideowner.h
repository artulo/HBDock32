#ifndef HBDOCKAUTOHIDEOWNER_H
#define HBDOCKAUTOHIDEOWNER_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideGetOwner(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideSetOwner(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HWND hOwner );

#ifdef __cplusplus
}
#endif

#endif