#ifndef HBDOCKAUTOHIDEPRESSED_H
#define HBDOCKAUTOHIDEPRESSED_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetPressed(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int bPressed );

int hbDockAutoHideIsPressed(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif