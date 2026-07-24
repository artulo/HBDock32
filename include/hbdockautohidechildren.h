#ifndef HBDOCKAUTOHIDECHILDREN_H
#define HBDOCKAUTOHIDECHILDREN_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideGetFirstChild(
   HB_DOCK_AUTOHIDE * pAutoHide );

HWND hbDockAutoHideGetNextSibling(
   HWND hWnd );

HWND hbDockAutoHideGetPreviousSibling(
   HWND hWnd );

#ifdef __cplusplus
}
#endif

#endif