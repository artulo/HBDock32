#ifndef HBDOCKTREEWALK_H
#define HBDOCKTREEWALK_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int ( * HB_DOCK_NODE_PROC )(
   HB_DOCK_NODE * pNode,
   void * Cargo );

void hbDockTreeWalk(
   HB_DOCK_NODE * pRoot,
   HB_DOCK_NODE_PROC pProc,
   void * Cargo );

#ifdef __cplusplus
}
#endif

#endif