#ifndef HBDOCKAUTOHIDEDELAY_H
#define HBDOCKAUTOHIDEDELAY_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetDelay(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT nDelay );

UINT hbDockAutoHideGetDelay(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif