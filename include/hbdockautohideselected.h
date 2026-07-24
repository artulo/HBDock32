#ifndef HBDOCKAUTOHIDESELECTED_H
#define HBDOCKAUTOHIDESELECTED_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSelect(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideUnselect(
   HB_DOCK_AUTOHIDE * pAutoHide );

int hbDockAutoHideIsSelected(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif