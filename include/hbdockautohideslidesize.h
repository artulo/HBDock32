#ifndef HBDOCKAUTOHIDESLIDESIZE_H
#define HBDOCKAUTOHIDESLIDESIZE_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetSlideSize(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nSize );

int hbDockAutoHideGetSlideSize(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif