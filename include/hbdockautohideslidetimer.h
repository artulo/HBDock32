#ifndef HBDOCKAUTOHIDESLIDETIMER_H
#define HBDOCKAUTOHIDESLIDETIMER_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideStartSlideTimer(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT nInterval );

void hbDockAutoHideStopSlideTimer(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif