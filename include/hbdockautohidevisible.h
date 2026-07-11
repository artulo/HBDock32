#ifndef HBDOCKAUTOHIDEVISIBLE_H
#define HBDOCKAUTOHIDEVISIBLE_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideShowWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideHideWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane );

BOOL hbDockAutoHideWindowVisible(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif