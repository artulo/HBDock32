#ifndef HBDOCKAUTOHIDESHOWSTATE_H
#define HBDOCKAUTOHIDESHOWSTATE_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideMinimize(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideMaximize(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideRestore(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif