#ifndef HBDOCKAUTOHIDEENABLEWINDOW_H
#define HBDOCKAUTOHIDEENABLEWINDOW_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideEnableWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   BOOL bEnable );

#ifdef __cplusplus
}
#endif

#endif