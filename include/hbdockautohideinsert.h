#ifndef HBDOCKAUTOHIDEINSERT_H
#define HBDOCKAUTOHIDEINSERT_H

#include "hbdockautohidemanager.h"
#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockAutoHideInsert(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   int nIndex,
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif