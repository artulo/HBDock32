#ifndef HBDOCKAUTOHIDESLIDEPOSITION_H
#define HBDOCKAUTOHIDESLIDEPOSITION_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetSlidePosition(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nPos );

int hbDockAutoHideGetSlidePosition(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif