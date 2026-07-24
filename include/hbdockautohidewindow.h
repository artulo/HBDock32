#ifndef HBDOCKAUTOHIDEWINDOW_H
#define HBDOCKAUTOHIDEWINDOW_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideGetWindow(
   HB_DOCK_AUTOHIDE * pAutoHide );


BOOL hbDockAutoHideIsWindow(
   HB_DOCK_AUTOHIDE * pAutoHide );


#ifdef __cplusplus
}
#endif

#endif