#ifndef HBDOCKAUTOHIDEBUTTONCAPTURE_H
#define HBDOCKAUTOHIDEBUTTONCAPTURE_H

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideButtonSetCapture(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

void hbDockAutoHideButtonReleaseCapture( void );

int hbDockAutoHideButtonHasCapture(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif