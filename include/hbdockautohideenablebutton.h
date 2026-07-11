#ifndef HBDOCKAUTOHIDEENABLEBUTTON_H
#define HBDOCKAUTOHIDEENABLEBUTTON_H

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideEnableButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

void hbDockAutoHideDisableButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

int hbDockAutoHideButtonEnabled(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif