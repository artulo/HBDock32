#ifndef HBDOCKAUTOHIDETRACK_H
#define HBDOCKAUTOHIDETRACK_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideBeginTrack(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideEndTrack(
   HB_DOCK_AUTOHIDE * pAutoHide );

int hbDockAutoHideIsTracking(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif