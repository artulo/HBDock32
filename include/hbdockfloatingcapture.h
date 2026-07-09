#ifndef HBDOCKFLOATINGCAPTURE_H
#define HBDOCKFLOATINGCAPTURE_H

#include <windows.h>
#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingSetCapture(
   HB_DOCK_FLOATING_FRAME * pFrame );

void hbDockFloatingReleaseCapture(
   HB_DOCK_FLOATING_FRAME * pFrame );

int hbDockFloatingHasCapture(
   const HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif