#ifndef HBDOCKAUTOHIDEENABLEDFLAG_H
#define HBDOCKAUTOHIDEENABLEDFLAG_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetEnabledFlag(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int bEnabled );

int hbDockAutoHideGetEnabledFlag(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif