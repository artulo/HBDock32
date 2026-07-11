#ifndef HBDOCKAUTOHIDEBUTTONFONT_H
#define HBDOCKAUTOHIDEBUTTONFONT_H

#include <windows.h>

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideButtonSetFont(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   HFONT hFont );

HFONT hbDockAutoHideButtonGetFont(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif