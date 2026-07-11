#ifndef HBDOCKAUTOHIDESLIDEENGINE_H
#define HBDOCKAUTOHIDESLIDEENGINE_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSlideIn(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideSlideOut(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideStopSlide(
   HB_DOCK_AUTOHIDE_PANE * pPane );

int hbDockAutoHideSlideRunning(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif