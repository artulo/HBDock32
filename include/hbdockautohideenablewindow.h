#ifndef HBDOCKAUTOHIDEENABLEWINDOW_H
#define HBDOCKAUTOHIDEENABLEWINDOW_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideEnableWindow(
   HB_DOCK_AUTOHIDE * pAutoHide,
   BOOL bEnable );

#ifdef __cplusplus
}
#endif

#endif