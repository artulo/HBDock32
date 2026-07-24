#ifndef HBDOCKAUTOHIDEACTIVATE_H
#define HBDOCKAUTOHIDEACTIVATE_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideActivate(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideDeactivate(
   HB_DOCK_AUTOHIDE * pAutoHide );

int hbDockAutoHideIsActive(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif