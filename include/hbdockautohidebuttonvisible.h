#ifndef HBDOCKAUTOHIDEBUTTONVISIBLE_H
#define HBDOCKAUTOHIDEBUTTONVISIBLE_H

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideButtonShow(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

void hbDockAutoHideButtonHide(
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

int hbDockAutoHideButtonIsVisible(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton );

#ifdef __cplusplus
}
#endif

#endif