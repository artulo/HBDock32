#ifndef HBDOCKAUTOHIDECREATE_H
#define HBDOCKAUTOHIDECREATE_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

HWND hbDockAutoHideCreate(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HWND hParent,
   LPCTSTR pszCaption );

#ifdef __cplusplus
}
#endif

#endif