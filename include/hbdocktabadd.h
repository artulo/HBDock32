#ifndef HBDOCKTABADD_H
#define HBDOCKTABADD_H

#include "hbdocktabgroup.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockTabAdd(
    HB_DOCK_TAB_GROUP * pGroup,
    HB_DOCK_PANEL * pPanel,
    LPCTSTR Caption );

#ifdef __cplusplus
}
#endif

#endif