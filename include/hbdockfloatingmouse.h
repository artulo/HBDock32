#ifndef HBDOCKFLOATINGMOUSE_H
#define HBDOCKFLOATINGMOUSE_H

#include <windows.h>
#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingGetMousePosition(
   HB_DOCK_FLOATING_FRAME * pFrame,
   POINT * pPoint );

int hbDockFloatingMouseInside(
   HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif