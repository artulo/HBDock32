#ifndef HBDOCKTREECOUNT_H
#define HBDOCKTREECOUNT_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockTreeCountLeaves(
   HB_DOCK_NODE * pRoot );

int hbDockTreeCountSplits(
   HB_DOCK_NODE * pRoot );

#ifdef __cplusplus
}
#endif

#endif