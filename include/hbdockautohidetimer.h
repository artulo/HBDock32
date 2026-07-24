#ifndef HBDOCKAUTOHIDETIMER_H
#define HBDOCKAUTOHIDETIMER_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

UINT_PTR hbDockAutoHideStartTimer(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT_PTR nId,
   UINT nElapse );


void hbDockAutoHideStopTimer(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT_PTR nId );


#ifdef __cplusplus
}
#endif

#endif