#ifndef HBDOCKAUTOHIDETEXT_H
#define HBDOCKAUTOHIDETEXT_H

#include <windows.h>

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockAutoHideGetTextLength(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideGetText(
   HB_DOCK_AUTOHIDE * pAutoHide,
   LPTSTR pszText,
   int nSize );

void hbDockAutoHideSetText(
   HB_DOCK_AUTOHIDE * pAutoHide,
   LPCTSTR pszText );

#ifdef __cplusplus
}
#endif

#endif