#ifndef HBDOCKAUTOHIDEFIRST_H
#define HBDOCKAUTOHIDEFIRST_H

#include "hbdockautohidemanager.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_AUTOHIDE_PANE *
hbDockAutoHideFirst(
   HB_DOCK_AUTOHIDE_MANAGER * pManager );

HB_DOCK_AUTOHIDE_PANE *
hbDockAutoHideLast(
   HB_DOCK_AUTOHIDE_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif