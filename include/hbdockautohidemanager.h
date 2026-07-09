#ifndef HBDOCKAUTOHIDEMANAGER_H
#define HBDOCKAUTOHIDEMANAGER_H

#include <windows.h>

#include "hbdockarray.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HWND hOwner;

   HB_DOCK_ARRAY Panes;

} HB_DOCK_AUTOHIDE_MANAGER;

void hbDockAutoHideManagerInit(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HWND hOwner );

void hbDockAutoHideManagerDestroy(
   HB_DOCK_AUTOHIDE_MANAGER * pManager );

int hbDockAutoHideManagerAdd(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   void * pPane );

int hbDockAutoHideManagerRemove(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   void * pPane );

int hbDockAutoHideManagerCount(
   const HB_DOCK_AUTOHIDE_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif