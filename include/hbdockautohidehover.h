#ifndef HBDOCKAUTOHIDEHOVER_H
#define HBDOCKAUTOHIDEHOVER_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideBeginHover(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideEndHover(
   HB_DOCK_AUTOHIDE_PANE * pPane );

int hbDockAutoHideIsHover(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif