#ifndef HBDOCKAUTOHIDEHITTEST_H
#define HBDOCKAUTOHIDEHITTEST_H

#include "hbdockautohidestrip.h"
#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_AUTOHIDE_BUTTON *
hbDockAutoHideHitTest(
   HB_DOCK_AUTOHIDE_STRIP * pStrip,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif