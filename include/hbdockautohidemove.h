#ifndef HBDOCKAUTOHIDEMOVE_H
#define HBDOCKAUTOHIDEMOVE_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideMove(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int x,
   int y );

void hbDockAutoHideResize(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int cx,
   int cy );

#ifdef __cplusplus
}
#endif

#endif