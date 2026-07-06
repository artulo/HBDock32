#ifndef HBDOCKTREEREMOVE_H
#define HBDOCKTREEREMOVE_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_NODE * hbDockTreeRemoveNode(
   HB_DOCK_NODE * pRoot,
   HB_DOCK_NODE * pNode );

#ifdef __cplusplus
}
#endif

#endif