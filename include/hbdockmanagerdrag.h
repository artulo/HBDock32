#ifndef HBDOCKMANAGERDRAG_H
#define HBDOCKMANAGERDRAG_H

#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockManagerBeginDrag(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   POINT pt );

void hbDockManagerDragMove(
   HB_DOCK_MANAGER * pManager,
   POINT pt );

void hbDockManagerEndDrag(
   HB_DOCK_MANAGER * pManager,
   POINT pt );

void hbDockManagerCancelDrag(
   HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif