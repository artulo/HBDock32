#ifndef HBDOCKFLOATINGSTYLE_H
#define HBDOCKFLOATINGSTYLE_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingSetStyle(
   HB_DOCK_FLOATING_FRAME * pFrame,
   DWORD dwStyle );

DWORD hbDockFloatingGetStyle(
   const HB_DOCK_FLOATING_FRAME * pFrame );

void hbDockFloatingSetExStyle(
   HB_DOCK_FLOATING_FRAME * pFrame,
   DWORD dwStyle );

DWORD hbDockFloatingGetExStyle(
   const HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif