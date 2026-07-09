#ifndef HBDOCKFLOATINGTIMER_H
#define HBDOCKFLOATINGTIMER_H

#include <windows.h>

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

UINT_PTR hbDockFloatingStartTimer(
   HB_DOCK_FLOATING_FRAME * pFrame,
   UINT_PTR nId,
   UINT nInterval );

void hbDockFloatingStopTimer(
   HB_DOCK_FLOATING_FRAME * pFrame,
   UINT_PTR nId );

#ifdef __cplusplus
}
#endif

#endif