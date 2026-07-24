#ifndef HBDOCKAUTOHIDEFOCUS_H
#define HBDOCKAUTOHIDEFOCUS_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetFocus(
   HB_DOCK_AUTOHIDE * pAutoHide );

int hbDockAutoHideHasFocus(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif