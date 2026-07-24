#ifndef HBDOCKAUTOHIDESIZE_H
#define HBDOCKAUTOHIDESIZE_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideGetSize(
   HB_DOCK_AUTOHIDE * pAutoHide,
   SIZE * pSize );

#ifdef __cplusplus
}
#endif

#endif