#ifndef HBDOCKTABREORDER_H
#define HBDOCKTABREORDER_H

#include "hbdocktabgroup.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockTabReorder(
      HB_DOCK_TAB_GROUP * pGroup,
      UINT OldIndex,
      UINT NewIndex );

#ifdef __cplusplus
}
#endif

#endif