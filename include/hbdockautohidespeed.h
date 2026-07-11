#ifndef HBDOCKAUTOHIDESPEED_H
#define HBDOCKAUTOHIDESPEED_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetSlideSpeed(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nSpeed );

int hbDockAutoHideGetSlideSpeed(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif