#ifndef HBDOCKAUTOHIDEACCELERATION_H
#define HBDOCKAUTOHIDEACCELERATION_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetAcceleration(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nAccel );

int hbDockAutoHideGetAcceleration(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif