#ifndef HBDOCKFLOATINGREGION_H
#define HBDOCKFLOATINGREGION_H

#include <windows.h>
#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingSetRegion(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HRGN hRegion,
   int bRedraw );

void hbDockFloatingClearRegion(
   HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif