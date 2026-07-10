#ifndef HBDOCKAUTOHIDEPANERECT_H
#define HBDOCKAUTOHIDEPANERECT_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHidePaneSetRect(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   const RECT * pRect );

void hbDockAutoHidePaneGetRect(
   const HB_DOCK_AUTOHIDE_PANE * pPane,
   RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif