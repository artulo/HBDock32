#ifndef HBDOCKAUTOHIDEBUTTONRECT_H
#define HBDOCKAUTOHIDEBUTTONRECT_H

#include <windows.h>

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideButtonGetRect(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   RECT * pRect );

BOOL hbDockAutoHideButtonGetClientRect(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif