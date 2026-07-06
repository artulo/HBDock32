#ifndef HBDOCKMANAGERLAYOUT_H
#define HBDOCKMANAGERLAYOUT_H

#include "hbdocklayoutengine.h"
#include "hbdockmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockManagerLayout(
   HB_DOCK_MANAGER * pManager );

void hbDockManagerResize(
   HB_DOCK_MANAGER * pManager,
   int cx,
   int cy );

#ifdef __cplusplus
}
#endif

#endif