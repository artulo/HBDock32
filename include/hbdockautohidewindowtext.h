#ifndef HBDOCKAUTOHIDEWINDOWTEXT_H
#define HBDOCKAUTOHIDEWINDOWTEXT_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideCopyWindowText(
   HB_DOCK_AUTOHIDE * pAutoHide,
   LPTSTR pszText,
   int nMax );

#ifdef __cplusplus
}
#endif

#endif