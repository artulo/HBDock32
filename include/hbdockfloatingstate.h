#ifndef HBDOCKFLOATINGSTATE_H
#define HBDOCKFLOATINGSTATE_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HB_FLOAT_STATE_HIDDEN     0
#define HB_FLOAT_STATE_NORMAL     1
#define HB_FLOAT_STATE_MINIMIZED  2
#define HB_FLOAT_STATE_MAXIMIZED  3

void hbDockFloatingSetState(
   HB_DOCK_FLOATING_FRAME * pFrame,
   int nState );

int hbDockFloatingGetState(
   const HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif