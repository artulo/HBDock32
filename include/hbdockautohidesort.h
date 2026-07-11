#ifndef HBDOCKAUTOHIDESORT_H
#define HBDOCKAUTOHIDESORT_H

#include "hbdockautohidemanager.h"
#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int ( * HB_DOCK_AUTOHIDE_COMPARE )(
   const HB_DOCK_AUTOHIDE_PANE * pLeft,
   const HB_DOCK_AUTOHIDE_PANE * pRight );

void hbDockAutoHideSort(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HB_DOCK_AUTOHIDE_COMPARE pCompare );

#ifdef __cplusplus
}
#endif

#endif