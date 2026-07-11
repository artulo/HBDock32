#ifndef HBDOCKAUTOHIDEBUTTONCHILDREN_H
#define HBDOCKAUTOHIDEBUTTONCHILDREN_H

#include <windows.h>
#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideButtonGetFirstChild(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

HWND hbDockAutoHideButtonGetNextSibling(
   HWND hWnd );

HWND hbDockAutoHideButtonGetPreviousSibling(
   HWND hWnd );

#ifdef __cplusplus
}
#endif

#endif