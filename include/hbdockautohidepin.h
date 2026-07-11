#ifndef HBDOCKAUTOHIDEPIN_H
#define HBDOCKAUTOHIDEPIN_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHidePin(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideUnpin(
   HB_DOCK_AUTOHIDE_PANE * pPane );

int hbDockAutoHideIsPinned(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif