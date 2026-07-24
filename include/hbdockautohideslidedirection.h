#ifndef HBDOCKAUTOHIDESLIDEDIRECTION_H
#define HBDOCKAUTOHIDESLIDEDIRECTION_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetDirection(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nDirection );

int hbDockAutoHideGetDirection(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif