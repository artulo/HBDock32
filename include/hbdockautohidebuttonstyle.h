#ifndef HBDOCKAUTOHIDEBUTTONSTYLE_H
#define HBDOCKAUTOHIDEBUTTONSTYLE_H

#include <windows.h>

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

DWORD hbDockAutoHideButtonGetStyle(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton );

void hbDockAutoHideButtonSetStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   DWORD dwStyle );

DWORD hbDockAutoHideButtonGetExStyle(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton );

void hbDockAutoHideButtonSetExStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   DWORD dwExStyle );

#ifdef __cplusplus
}
#endif

#endif