#ifndef HBDOCKAUTOHIDESPEED_H
#define HBDOCKAUTOHIDESPEED_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetSlideSpeed(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nSpeed );

int hbDockAutoHideGetSlideSpeed(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif