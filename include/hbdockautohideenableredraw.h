#ifndef HBDOCKAUTOHIDEENABLEREDRAW_H
#define HBDOCKAUTOHIDEENABLEREDRAW_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideLockRedraw(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideUnlockRedraw(
   HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif