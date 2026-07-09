#ifndef HBDOCKFLOATINGICON_H
#define HBDOCKFLOATINGICON_H

#include <windows.h>
#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingSetIcon(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HICON hIcon );

HICON hbDockFloatingGetIcon(
   HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif