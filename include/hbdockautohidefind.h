#ifndef HBDOCKAUTOHIDEFIND_H
#define HBDOCKAUTOHIDEFIND_H

#include "hbdockautohidemanager.h"
#include "hbdockautohide.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_AUTOHIDE *
hbDockAutoHideFindPanel(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif