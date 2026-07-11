#ifndef HBDOCKAUTOHIDEFOCUS_H
#define HBDOCKAUTOHIDEFOCUS_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetFocus(
   HB_DOCK_AUTOHIDE_PANE * pPane );

int hbDockAutoHideHasFocus(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif