#ifndef HBDOCKAUTOHIDEBUTTONICON_H
#define HBDOCKAUTOHIDEBUTTONICON_H

#include <windows.h>

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideButtonSetIcon(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   HICON hIcon );

HICON hbDockAutoHideButtonGetIcon(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif