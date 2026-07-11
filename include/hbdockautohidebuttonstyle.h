#ifndef HBDOCKAUTOHIDEBUTTONSTYLE_H
#define HBDOCKAUTOHIDEBUTTONSTYLE_H

#include <windows.h>

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

LONG hbDockAutoHideButtonGetStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

void hbDockAutoHideButtonSetStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   LONG lStyle );

LONG hbDockAutoHideButtonGetExStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

void hbDockAutoHideButtonSetExStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   LONG lStyle );

#ifdef __cplusplus
}
#endif

#endif