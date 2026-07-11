#ifndef HBDOCKAUTOHIDEZORDER_H
#define HBDOCKAUTOHIDEZORDER_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideBringToFront(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideSendToBack(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif