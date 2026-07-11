#ifndef HBDOCKAUTOHIDEBUTTONGEOMETRY_H
#define HBDOCKAUTOHIDEBUTTONGEOMETRY_H

#include <windows.h>

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideButtonGetRect(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   RECT * pRect );

BOOL hbDockAutoHideButtonSetRect(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   const RECT * pRect,
   BOOL bRepaint );

#ifdef __cplusplus
}
#endif

#endif
