#ifndef HBDOCKAUTOHIDECHILDREN_H
#define HBDOCKAUTOHIDECHILDREN_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideGetFirstChild(
   HB_DOCK_AUTOHIDE_PANE * pPane );

HWND hbDockAutoHideGetNextSibling(
   HWND hWnd );

HWND hbDockAutoHideGetPreviousSibling(
   HWND hWnd );

#ifdef __cplusplus
}
#endif

#endif