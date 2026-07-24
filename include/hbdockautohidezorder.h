#ifndef HBDOCKAUTOHIDEZORDER_H
#define HBDOCKAUTOHIDEZORDER_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideBringToFront(
   HB_DOCK_AUTOHIDE * pAutoHide );


void hbDockAutoHideSendToBack(
   HB_DOCK_AUTOHIDE * pAutoHide );


#ifdef __cplusplus
}
#endif

#endif