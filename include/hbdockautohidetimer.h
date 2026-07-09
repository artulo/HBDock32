#ifndef HBDOCKAUTOHIDETIMER_H
#define HBDOCKAUTOHIDETIMER_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

UINT_PTR hbDockAutoHideStartTimer(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT Interval );

void hbDockAutoHideStopTimer(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif