#ifndef HBDOCKAUTOHIDESTARTMANAGER_H
#define HBDOCKAUTOHIDESTARTMANAGER_H

#include "hbdockautohideanimationmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockAutoHideAnimationStart(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager,
   HWND hWnd );

void hbDockAutoHideAnimationStop(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager,
   HWND hWnd );

#ifdef __cplusplus
}
#endif

#endif