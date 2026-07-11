#ifndef HBDOCKAUTOHIDEOWNER_H
#define HBDOCKAUTOHIDEOWNER_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideGetOwner(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideSetOwner(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HWND hOwner );

#ifdef __cplusplus
}
#endif

#endif