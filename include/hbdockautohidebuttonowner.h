#ifndef HBDOCKAUTOHIDEBUTTONOWNER_H
#define HBDOCKAUTOHIDEBUTTONOWNER_H

#include <windows.h>
#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideButtonGetOwner(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif