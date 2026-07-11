#ifndef HBDOCKAUTOHIDEDELAY_H
#define HBDOCKAUTOHIDEDELAY_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetDelay(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT nDelay );

UINT hbDockAutoHideGetDelay(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif