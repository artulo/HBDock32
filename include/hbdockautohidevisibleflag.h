#ifndef HBDOCKAUTOHIDEVISIBLEFLAG_H
#define HBDOCKAUTOHIDEVISIBLEFLAG_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetVisibleFlag(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int bVisible );

int hbDockAutoHideGetVisibleFlag(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif