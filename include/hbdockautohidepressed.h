#ifndef HBDOCKAUTOHIDEPRESSED_H
#define HBDOCKAUTOHIDEPRESSED_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetPressed(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int bPressed );

int hbDockAutoHideIsPressed(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif