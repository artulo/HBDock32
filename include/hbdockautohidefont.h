#ifndef HBDOCKAUTOHIDEFONT_H
#define HBDOCKAUTOHIDEFONT_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetFont(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HFONT hFont );

HFONT hbDockAutoHideGetFont(
   HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif