#ifndef HBDOCKAUTOHIDESLIDEPOSITION_H
#define HBDOCKAUTOHIDESLIDEPOSITION_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetSlidePosition(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nPos );

int hbDockAutoHideGetSlidePosition(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif