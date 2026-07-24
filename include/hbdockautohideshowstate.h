#ifndef HBDOCKAUTOHIDESHOWSTATE_H
#define HBDOCKAUTOHIDESHOWSTATE_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideMinimize(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideMaximize(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideRestore(
   HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif