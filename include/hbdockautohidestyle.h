#ifndef HBDOCKAUTOHIDESTYLE_H
#define HBDOCKAUTOHIDESTYLE_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

LONG hbDockAutoHideGetStyle(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideSetStyle(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   LONG lStyle );

LONG hbDockAutoHideGetExStyle(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideSetExStyle(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   LONG lStyle );

#ifdef __cplusplus
}
#endif

#endif