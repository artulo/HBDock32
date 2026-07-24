#ifndef HBDOCKMANAGERTABIFY_H
#define HBDOCKMANAGERTABIFY_H

#include "hbdockmanager.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockManagerTabifyPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif