#ifndef HBDOCKTABADD_H
#define HBDOCKTABADD_H

#include "hbdocktabgroup.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockTabAdd(
      HB_DOCK_TAB_GROUP * pGroup,
      HWND hDock,
      LPCTSTR Caption );

#ifdef __cplusplus
}
#endif

#endif