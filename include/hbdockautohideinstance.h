#ifndef HBDOCKAUTOHIDEINSTANCE_H
#define HBDOCKAUTOHIDEINSTANCE_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

HINSTANCE hbDockAutoHideGetInstance(
   HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif