#ifndef HBDOCKAUTOHIDELOCK_H
#define HBDOCKAUTOHIDELOCK_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideLock(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideUnlock(
   HB_DOCK_AUTOHIDE * pAutoHide );

int hbDockAutoHideIsLocked(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif