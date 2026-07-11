#ifndef HBDOCKAUTOHIDECAPTURE_H
#define HBDOCKAUTOHIDECAPTURE_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetCapture(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideReleaseCapture( void );

int hbDockAutoHideHasCapture(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif