#ifndef HBDOCKAUTOHIDEHOTTRACK_H
#define HBDOCKAUTOHIDEHOTTRACK_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetHotTrack(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int bEnable );

int hbDockAutoHideGetHotTrack(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif