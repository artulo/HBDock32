#ifndef HBDOCKAUTOHIDEWINDOWID_H
#define HBDOCKAUTOHIDEWINDOWID_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockAutoHideGetWindowId(
   HB_DOCK_AUTOHIDE * pAutoHide );


void hbDockAutoHideSetWindowId(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nId );


#ifdef __cplusplus
}
#endif

#endif