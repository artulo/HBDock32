#ifndef HBDOCKAUTOHIDEINSTANCE_H
#define HBDOCKAUTOHIDEINSTANCE_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

HINSTANCE hbDockAutoHideGetInstance(
   HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif