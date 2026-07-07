#ifndef HBDOCKFLOATINGMOVE_H
#define HBDOCKFLOATINGMOVE_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingMove(
   HB_DOCK_FLOATING_FRAME * pFrame,
   int x,
   int y );

void hbDockFloatingResize(
   HB_DOCK_FLOATING_FRAME * pFrame,
   int cx,
   int cy );

#ifdef __cplusplus
}
#endif

#endif