#ifndef HBDOCKAUTOHIDEICON_H
#define HBDOCKAUTOHIDEICON_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetIcon(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HICON hIcon );

HICON hbDockAutoHideGetIcon(
   HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif