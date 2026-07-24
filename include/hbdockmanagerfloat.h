#ifndef HBDOCKMANAGERFLOAT_H
#define HBDOCKMANAGERFLOAT_H

#include "hbdockmanager.h"
#include "hbdockcontainer.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockManagerFloat(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_CONTAINER * pContainer,
   const RECT * pRect );

void hbDockManagerFloatPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif