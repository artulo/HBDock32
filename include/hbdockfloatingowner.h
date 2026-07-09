#ifndef HBDOCKFLOATINGOWNER_H
#define HBDOCKFLOATINGOWNER_H

#include <windows.h>

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingSetOwner(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HWND hOwner );

HWND hbDockFloatingGetOwner(
   const HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif