#ifndef HBDOCKAUTOHIDECLIENT_H
#define HBDOCKAUTOHIDECLIENT_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideGetClientRect(
   HB_DOCK_AUTOHIDE * pAutoHide,
   RECT * pRect );

void hbDockAutoHideClientToScreen(
   HB_DOCK_AUTOHIDE * pAutoHide,
   POINT * pPoint );

void hbDockAutoHideScreenToClient(
   HB_DOCK_AUTOHIDE * pAutoHide,
   POINT * pPoint );

#ifdef __cplusplus
}
#endif

#endif