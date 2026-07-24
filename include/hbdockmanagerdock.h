#ifndef HBDOCKMANAGERDOCK_H
#define HBDOCKMANAGERDOCK_H

#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockguidemanager.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockManagerDockPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_GUIDE_TYPE Guide );
   


#ifdef __cplusplus
}
#endif

#endif /* HBDOCKMANAGERDOCK_H */