#ifndef HBDOCKFLOATINGACTIVATE_H
#define HBDOCKFLOATINGACTIVATE_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingActivate(
   HB_DOCK_FLOATING_FRAME * pFrame );

void hbDockFloatingDeactivate(
   HB_DOCK_FLOATING_FRAME * pFrame );

int hbDockFloatingIsActive(
   const HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif