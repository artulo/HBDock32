#ifndef HBDOCKAUTOHIDESLIDEENGINE_H
#define HBDOCKAUTOHIDESLIDEENGINE_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSlideIn(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideSlideOut(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideStopSlide(
   HB_DOCK_AUTOHIDE * pAutoHide );

int hbDockAutoHideSlideRunning(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif