#ifndef HBDOCKAUTOHIDESLIDETIMER_H
#define HBDOCKAUTOHIDESLIDETIMER_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideStartSlideTimer(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT nInterval );

void hbDockAutoHideStopSlideTimer(
   HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif