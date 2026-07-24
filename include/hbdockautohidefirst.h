#ifndef HBDOCKAUTOHIDEFIRST_H
#define HBDOCKAUTOHIDEFIRST_H

#include "hbdockautohidemanager.h"
#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_AUTOHIDE *
hbDockAutoHideFirst(
   HB_DOCK_AUTOHIDE_MANAGER * pManager );

HB_DOCK_AUTOHIDE *
hbDockAutoHideLast(
   HB_DOCK_AUTOHIDE_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif