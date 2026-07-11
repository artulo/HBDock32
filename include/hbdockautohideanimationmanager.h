#ifndef HBDOCKAUTOHIDEANIMATIONMANAGER_H
#define HBDOCKAUTOHIDEANIMATIONMANAGER_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_AUTOHIDE_ANIMATION_MANAGER
{
   HB_DOCK_AUTOHIDE_PANE ** pPanes;
   int Count;
   int Capacity;
   UINT TimerId;
   UINT Interval;

} HB_DOCK_AUTOHIDE_ANIMATION_MANAGER;

void hbDockAutoHideAnimationManagerInit(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager );

void hbDockAutoHideAnimationManagerDone(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif