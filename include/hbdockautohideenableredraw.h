#ifndef HBDOCKAUTOHIDEENABLEREDRAW_H
#define HBDOCKAUTOHIDEENABLEREDRAW_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideLockRedraw(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideUnlockRedraw(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif