#ifndef HBDOCKAUTOHIDESTATE_H
#define HBDOCKAUTOHIDESTATE_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetState(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   DWORD dwState );

DWORD hbDockAutoHideGetState(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif