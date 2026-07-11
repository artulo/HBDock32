#ifndef HBDOCKAUTOHIDEPARENT_H
#define HBDOCKAUTOHIDEPARENT_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideGetParent(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideSetParent(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HWND hParent );

#ifdef __cplusplus
}
#endif

#endif