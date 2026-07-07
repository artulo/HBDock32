#ifndef HBDOCKTREECOUNT_H
#define HBDOCKTREECOUNT_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockTreeNodeCount(
   HB_DOCK_NODE * pRoot );

int hbDockTreeLeafCount(
   HB_DOCK_NODE * pRoot );

int hbDockTreeSplitCount(
   HB_DOCK_NODE * pRoot );

#ifdef __cplusplus
}
#endif

#endif