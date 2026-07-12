#ifndef HBDOCKGUIDEMANAGER_H
#define HBDOCKGUIDEMANAGER_H

#include "hbdockguide.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HB_DOCK_GUIDE_COUNT 5

typedef struct _HB_DOCK_GUIDE_MANAGER
{
   HB_DOCK_GUIDE Guides[ HB_DOCK_GUIDE_COUNT ];

   HWND hOwner;

   BOOL Visible;

} HB_DOCK_GUIDE_MANAGER;

BOOL hbDockGuideManagerInit(
   HB_DOCK_GUIDE_MANAGER * pManager,
   HWND hOwner );

void hbDockGuideManagerDestroy(
   HB_DOCK_GUIDE_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif