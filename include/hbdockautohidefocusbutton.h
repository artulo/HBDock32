#ifndef HBDOCKAUTOHIDEFOCUSBUTTON_H
#define HBDOCKAUTOHIDEFOCUSBUTTON_H

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideFocusButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

int hbDockAutoHideButtonHasFocus(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif