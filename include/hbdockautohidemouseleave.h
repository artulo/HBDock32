#ifndef HBDOCKAUTOHIDEMOUSELEAVE_H
#define HBDOCKAUTOHIDEMOUSELEAVE_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideBeginMouseLeave(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideEndMouseLeave(
   HB_DOCK_AUTOHIDE * pAutoHide );

int hbDockAutoHideWaitingMouseLeave(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif