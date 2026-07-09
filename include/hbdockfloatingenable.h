#ifndef HBDOCKFLOATINGENABLE_H
#define HBDOCKFLOATINGENABLE_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingEnable(
   HB_DOCK_FLOATING_FRAME * pFrame );

void hbDockFloatingDisable(
   HB_DOCK_FLOATING_FRAME * pFrame );

int hbDockFloatingIsEnabled(
   const HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif