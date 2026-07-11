#ifndef HBDOCKAUTOHIDEREDRAWWINDOW_H
#define HBDOCKAUTOHIDEREDRAWWINDOW_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideRedrawWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT uFlags );

#ifdef __cplusplus
}
#endif

#endif