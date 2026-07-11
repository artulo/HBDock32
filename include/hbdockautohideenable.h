#ifndef HBDOCKAUTOHIDEENABLE_H
#define HBDOCKAUTOHIDEENABLE_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideEnable(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideDisable(
   HB_DOCK_AUTOHIDE_PANE * pPane );

int hbDockAutoHideIsEnabled(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif