#ifndef HBDOCKAUTOHIDEPOSITION_H
#define HBDOCKAUTOHIDEPOSITION_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideGetPosition(
   HB_DOCK_AUTOHIDE * pAutoHide,
   POINT * pPoint );

#ifdef __cplusplus
}
#endif

#endif