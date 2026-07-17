#ifndef HBDOCKAUTOHIDEBUTTONGEOMETRY_H
#define HBDOCKAUTOHIDEBUTTONGEOMETRY_H

#include <windows.h>
#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideButtonGetRect(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton,
   RECT * pRect );

void hbDockAutoHideButtonSetRect(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   const RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif