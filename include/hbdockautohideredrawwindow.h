#ifndef HBDOCKAUTOHIDEREDRAWWINDOW_H
#define HBDOCKAUTOHIDEREDRAWWINDOW_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideRedrawWindow(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT uFlags );

#ifdef __cplusplus
}
#endif

#endif