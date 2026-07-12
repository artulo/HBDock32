#ifndef HBDOCKCONTAINERADDTAB_H
#define HBDOCKCONTAINERADDTAB_H

#include "hbdockcontainer.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockContainerAddTab(
      HB_DOCK_CONTAINER * pContainer,
      HWND hDock,
      LPCTSTR Caption );

#ifdef __cplusplus
}
#endif

#endif