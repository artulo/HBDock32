#ifndef HBDOCKAUTOHIDECLIENT_H
#define HBDOCKAUTOHIDECLIENT_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideGetClientRect(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   RECT * pRect );

void hbDockAutoHideClientToScreen(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   POINT * pPoint );

void hbDockAutoHideScreenToClient(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   POINT * pPoint );

#ifdef __cplusplus
}
#endif

#endif