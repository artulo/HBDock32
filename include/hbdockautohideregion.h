#ifndef HBDOCKAUTOHIDEREGION_H
#define HBDOCKAUTOHIDEREGION_H

#include <windows.h>
#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetRegion(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HRGN hRegion,
   BOOL bRedraw );

void hbDockAutoHideClearRegion(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif