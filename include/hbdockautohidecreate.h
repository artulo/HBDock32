#ifndef HBDOCKAUTOHIDECREATE_H
#define HBDOCKAUTOHIDECREATE_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideCreate(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HWND hParent,
   LPCTSTR pszCaption );

#ifdef __cplusplus
}
#endif

#endif