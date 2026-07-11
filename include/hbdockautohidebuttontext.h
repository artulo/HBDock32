#ifndef HBDOCKAUTOHIDEBUTTONTEXT_H
#define HBDOCKAUTOHIDEBUTTONTEXT_H

#include <windows.h>

#include "hbdockautohidebutton.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideButtonSetText(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   LPCTSTR pszText );

int hbDockAutoHideButtonGetText(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   LPTSTR pszText,
   int nMax );

#ifdef __cplusplus
}
#endif

#endif