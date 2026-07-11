#ifndef HBDOCKAUTOHIDETRACK_H
#define HBDOCKAUTOHIDETRACK_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideBeginTrack(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideEndTrack(
   HB_DOCK_AUTOHIDE_PANE * pPane );

int hbDockAutoHideIsTracking(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif