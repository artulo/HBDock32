#ifndef HBDOCKFLOATINGFONT_H
#define HBDOCKFLOATINGFONT_H

#include <windows.h>

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingSetFont(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HFONT hFont );

HFONT hbDockFloatingGetFont(
   HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif