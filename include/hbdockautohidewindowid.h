#ifndef HBDOCKAUTOHIDEWINDOWID_H
#define HBDOCKAUTOHIDEWINDOWID_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockAutoHideGetWindowId(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideSetWindowId(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nId );

#ifdef __cplusplus
}
#endif

#endif