#ifndef HBDOCKMANAGERUNDOCK_H
#define HBDOCKMANAGERUNDOCK_H

#include "hbdockmanager.h"
#include "hbdockcontainer.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockManagerUndock(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_CONTAINER * pContainer );

void hbDockManagerUndockPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );


#ifdef __cplusplus
}
#endif

#endif
