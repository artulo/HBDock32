#ifndef HBDOCKFLOATINGCLIENT_H
#define HBDOCKFLOATINGCLIENT_H

#include <windows.h>

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingGetClientRect(
   HB_DOCK_FLOATING_FRAME * pFrame,
   RECT * pRect );

void hbDockFloatingClientToScreen(
   HB_DOCK_FLOATING_FRAME * pFrame,
   POINT * pPoint );

void hbDockFloatingScreenToClient(
   HB_DOCK_FLOATING_FRAME * pFrame,
   POINT * pPoint );

#ifdef __cplusplus
}
#endif

#endif