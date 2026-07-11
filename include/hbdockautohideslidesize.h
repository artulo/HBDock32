#ifndef HBDOCKAUTOHIDESLIDESIZE_H
#define HBDOCKAUTOHIDESLIDESIZE_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetSlideSize(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nSize );

int hbDockAutoHideGetSlideSize(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif