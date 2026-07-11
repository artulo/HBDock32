#ifndef HBDOCKAUTOHIDEENABLEDFLAG_H
#define HBDOCKAUTOHIDEENABLEDFLAG_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetEnabledFlag(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int bEnabled );

int hbDockAutoHideGetEnabledFlag(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif