#ifndef HBDOCKAUTOHIDESTYLE_H
#define HBDOCKAUTOHIDESTYLE_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

LONG hbDockAutoHideGetStyle(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideSetStyle(
   HB_DOCK_AUTOHIDE * pAutoHide,
   LONG lStyle );

LONG hbDockAutoHideGetExStyle(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideSetExStyle(
   HB_DOCK_AUTOHIDE * pAutoHide,
   LONG lStyle );

#ifdef __cplusplus
}
#endif

#endif