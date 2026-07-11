#ifndef HBDOCKAUTOHIDELOCK_H
#define HBDOCKAUTOHIDELOCK_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideLock(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideUnlock(
   HB_DOCK_AUTOHIDE_PANE * pPane );

int hbDockAutoHideIsLocked(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif