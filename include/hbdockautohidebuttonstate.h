#ifndef HBDOCKAUTOHIDEBUTTONSTATE_H
#define HBDOCKAUTOHIDEBUTTONSTATE_H

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideButtonSetHot(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   int bHot );

void hbDockAutoHideButtonSetPressed(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   int bPressed );

int hbDockAutoHideButtonIsHot(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton );

int hbDockAutoHideButtonIsPressed(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif