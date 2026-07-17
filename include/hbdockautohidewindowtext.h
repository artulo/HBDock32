#ifndef HBDOCKAUTOHIDEWINDOWTEXT_H
#define HBDOCKAUTOHIDEWINDOWTEXT_H

#include <windows.h>

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockAutoHideCopyWindowText(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   LPTSTR pszText,
   int nMax );

#ifdef __cplusplus
}
#endif

#endif