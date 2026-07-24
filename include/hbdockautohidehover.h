#ifndef HBDOCKAUTOHIDEHOVER_H
#define HBDOCKAUTOHIDEHOVER_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideBeginHover(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideEndHover(
   HB_DOCK_AUTOHIDE * pAutoHide );

int hbDockAutoHideIsHover(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif