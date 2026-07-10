#ifndef HBDOCKAUTOHIDEBUTTONLIST_H
#define HBDOCKAUTOHIDEBUTTONLIST_H

#include "hbdockautohidestrip.h"
#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockAutoHideButtonAdd(
   HB_DOCK_AUTOHIDE_STRIP * pStrip,
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

int hbDockAutoHideButtonRemove(
   HB_DOCK_AUTOHIDE_STRIP * pStrip,
   HB_DOCK_AUTOHIDE_BUTTON * pButton );

HB_DOCK_AUTOHIDE_BUTTON *
hbDockAutoHideButtonGet(
   HB_DOCK_AUTOHIDE_STRIP * pStrip,
   int nIndex );

#ifdef __cplusplus
}
#endif

#endif