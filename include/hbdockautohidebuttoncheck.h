#ifndef HBDOCKAUTOHIDEBUTTONCHECK_H
#define HBDOCKAUTOHIDEBUTTONCHECK_H

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideButtonCheck(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

void hbDockAutoHideButtonUncheck(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

int hbDockAutoHideButtonIsChecked(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif