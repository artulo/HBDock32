#ifndef HBDOCKFLOATINGRECT_H
#define HBDOCKFLOATINGRECT_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingGetRect(
   HB_DOCK_FLOATING_FRAME * pFrame,
   RECT * pRect );

void hbDockFloatingSetRect(
   HB_DOCK_FLOATING_FRAME * pFrame,
   const RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif