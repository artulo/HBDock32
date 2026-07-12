#ifndef HBDOCKMANAGERDRAG_H
#define HBDOCKMANAGERDRAG_H

#include "hbdockmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockManagerBeginDrag(
      HB_DOCK_MANAGER * pManager,
      HWND hWnd );

void hbDockManagerEndDrag(
      HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif