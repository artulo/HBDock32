#ifndef HBDOCKAUTOHIDEACCELERATION_H
#define HBDOCKAUTOHIDEACCELERATION_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetAcceleration(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nAccel );

int hbDockAutoHideGetAcceleration(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif