#ifndef HBDOCKAUTOHIDEBUTTONPARENT_H
#define HBDOCKAUTOHIDEBUTTONPARENT_H

#include <windows.h>
#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideButtonGetParent(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

void hbDockAutoHideButtonSetParent(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   HWND hParent );

#ifdef __cplusplus
}
#endif

#endif