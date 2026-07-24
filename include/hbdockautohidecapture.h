#ifndef HBDOCKAUTOHIDECAPTURE_H
#define HBDOCKAUTOHIDECAPTURE_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetCapture(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideReleaseCapture( void );

int hbDockAutoHideHasCapture(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif