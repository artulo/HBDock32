#ifndef HBDOCKTREEWALK_H
#define HBDOCKTREEWALK_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*HB_DOCK_TREE_PROC)
(
   HB_DOCK_NODE * pNode,
   void * pCargo
);

void hbDockTreeWalk(
   HB_DOCK_NODE * pNode,
   HB_DOCK_TREE_PROC pProc,
   void * pCargo );

#ifdef __cplusplus
}
#endif

#endif