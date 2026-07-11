#ifndef HBDOCKAUTOHIDETEXT_H
#define HBDOCKAUTOHIDETEXT_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockAutoHideGetTextLength(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideGetText(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   LPTSTR pszText,
   int nSize );

void hbDockAutoHideSetText(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   LPCTSTR pszText );

#ifdef __cplusplus
}
#endif

#endif