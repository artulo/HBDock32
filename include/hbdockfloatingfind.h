#ifndef HBDOCKFLOATINGFIND_H
#define HBDOCKFLOATINGFIND_H

#include "hbdockfloatingmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_FLOATING_FRAME * hbDockFloatingFindByWindow(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HWND hWnd );

HB_DOCK_FLOATING_FRAME * hbDockFloatingFindByPanel(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif