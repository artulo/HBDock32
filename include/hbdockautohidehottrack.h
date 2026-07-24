#ifndef HBDOCKAUTOHIDEHOTTRACK_H
#define HBDOCKAUTOHIDEHOTTRACK_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetHotTrack(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int bEnable );

int hbDockAutoHideGetHotTrack(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif