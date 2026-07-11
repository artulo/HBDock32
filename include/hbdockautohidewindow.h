#ifndef HBDOCKAUTOHIDEWINDOW_H
#define HBDOCKAUTOHIDEWINDOW_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideGetWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane );

BOOL hbDockAutoHideIsWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif