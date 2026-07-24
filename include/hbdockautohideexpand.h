#ifndef HBDOCKAUTOHIDEEXPAND_H
#define HBDOCKAUTOHIDEEXPAND_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideExpand(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideCollapse(
   HB_DOCK_AUTOHIDE * pAutoHide );

int hbDockAutoHideIsExpanded(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif