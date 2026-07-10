#ifndef HBDOCKAUTOHIDEPANEVISIBLE_H
#define HBDOCKAUTOHIDEPANEVISIBLE_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHidePaneSetVisible(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int bVisible );

int hbDockAutoHidePaneIsVisible(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif