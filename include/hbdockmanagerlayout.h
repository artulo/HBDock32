#ifndef HBDOCKMANAGERLAYOUT_H
#define HBDOCKMANAGERLAYOUT_H

#include "hbdockmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockManagerLayout(
   HB_DOCK_MANAGER * pManager );

BOOL hbDockManagerLayoutRect(
   HB_DOCK_MANAGER * pManager,
   const RECT * pRect );

void hbDockManagerInvalidateLayout(
   HB_DOCK_MANAGER * pManager );

void hbDockManagerUpdateLayout(
   HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif