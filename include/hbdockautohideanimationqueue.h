#ifndef HBDOCKAUTOHIDEANIMATIONQUEUE_H
#define HBDOCKAUTOHIDEANIMATIONQUEUE_H

#include "hbdockautohideanimationmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockAutoHideAnimationIsQueued(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager,
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideAnimationClear(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif