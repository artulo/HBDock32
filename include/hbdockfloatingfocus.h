#ifndef HBDOCKFLOATINGFOCUS_H
#define HBDOCKFLOATINGFOCUS_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingSetFocus(
   HB_DOCK_FLOATING_FRAME * pFrame );

int hbDockFloatingHasFocus(
   const HB_DOCK_FLOATING_FRAME * pFrame );

HWND hbDockFloatingGetFocus(
   const HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif