#ifndef HBDOCKAUTOHIDEANIMATIONPAUSE_H
#define HBDOCKAUTOHIDEANIMATIONPAUSE_H

#include "hbdockautohideanimationmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideAnimationPause(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager );

void hbDockAutoHideAnimationResume(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif