#ifndef HBDOCKAUTOHIDEGET_H
#define HBDOCKAUTOHIDEGET_H

#include "hbdockautohidemanager.h"
#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_AUTOHIDE_PANE *
hbDockAutoHidePaneGet(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   int nIndex );

#ifdef __cplusplus
}
#endif

#endif