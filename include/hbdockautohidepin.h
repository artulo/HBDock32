#ifndef HBDOCKAUTOHIDEPIN_H
#define HBDOCKAUTOHIDEPIN_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHidePin(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideUnpin(
   HB_DOCK_AUTOHIDE * pAutoHide );

int hbDockAutoHideIsPinned(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif