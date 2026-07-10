#ifndef HBDOCKAUTOHIDESIDE_H
#define HBDOCKAUTOHIDESIDE_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HB_AUTOHIDE_LEFT    0
#define HB_AUTOHIDE_RIGHT   1
#define HB_AUTOHIDE_TOP     2
#define HB_AUTOHIDE_BOTTOM  3

void hbDockAutoHidePaneSetSide(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   DWORD nSide );

DWORD hbDockAutoHidePaneGetSide(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif