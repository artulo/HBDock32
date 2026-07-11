#ifndef HBDOCKAUTOHIDEEXPAND_H
#define HBDOCKAUTOHIDEEXPAND_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideExpand(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideCollapse(
   HB_DOCK_AUTOHIDE_PANE * pPane );

int hbDockAutoHideIsExpanded(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif