#ifndef HBDOCKAUTOHIDEFONT_H
#define HBDOCKAUTOHIDEFONT_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideSetFont(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HFONT hFont );

HFONT hbDockAutoHideGetFont(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif