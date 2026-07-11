#ifndef HBDOCKAUTOHIDEICON_H
#define HBDOCKAUTOHIDEICON_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetIcon(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HICON hIcon );

HICON hbDockAutoHideGetIcon(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif