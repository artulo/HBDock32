#ifndef HBDOCKAUTOHIDESLIDEDIRECTION_H
#define HBDOCKAUTOHIDESLIDEDIRECTION_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetDirection(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nDirection );

int hbDockAutoHideGetDirection(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif