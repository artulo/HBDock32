#ifndef HBDOCKAUTOHIDEMOUSE_H
#define HBDOCKAUTOHIDEMOUSE_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideGetMousePos(
   POINT * pPoint );

int hbDockAutoHideMouseInside(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif