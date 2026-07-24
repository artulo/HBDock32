#ifndef HBDOCKAUTOHIDEMOVE_H
#define HBDOCKAUTOHIDEMOVE_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideMove(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int x,
   int y );

void hbDockAutoHideResize(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int cx,
   int cy );

#ifdef __cplusplus
}
#endif

#endif