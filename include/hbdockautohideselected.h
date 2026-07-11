#ifndef HBDOCKAUTOHIDESELECTED_H
#define HBDOCKAUTOHIDESELECTED_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSelect(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideUnselect(
   HB_DOCK_AUTOHIDE_PANE * pPane );

int hbDockAutoHideIsSelected(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif