#ifndef HBDOCKAUTOHIDEMOUSELEAVE_H
#define HBDOCKAUTOHIDEMOUSELEAVE_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideBeginMouseLeave(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideEndMouseLeave(
   HB_DOCK_AUTOHIDE_PANE * pPane );

int hbDockAutoHideWaitingMouseLeave(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif