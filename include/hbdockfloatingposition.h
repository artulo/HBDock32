#ifndef HBDOCKFLOATINGPOSITION_H
#define HBDOCKFLOATINGPOSITION_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingSetPosition(
   HB_DOCK_FLOATING_FRAME * pFrame,
   const RECT * pRect );

void hbDockFloatingGetPosition(
   const HB_DOCK_FLOATING_FRAME * pFrame,
   RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif