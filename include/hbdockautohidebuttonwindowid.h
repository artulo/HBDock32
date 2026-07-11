#ifndef HBDOCKAUTOHIDEBUTTONWINDOWID_H
#define HBDOCKAUTOHIDEBUTTONWINDOWID_H

#include <windows.h>
#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockAutoHideButtonGetWindowId(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

void hbDockAutoHideButtonSetWindowId(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   int nId );

#ifdef __cplusplus
}
#endif

#endif