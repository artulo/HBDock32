#ifndef HBDOCKNODEPOOL_H
#define HBDOCKNODEPOOL_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_NODE_POOL
{
   HB_DOCK_NODE * FreeList;

} HB_DOCK_NODE_POOL;

void hbDockNodePoolInit(
   HB_DOCK_NODE_POOL * pPool );

HB_DOCK_NODE * hbDockNodePoolAlloc(
   HB_DOCK_NODE_POOL * pPool );

void hbDockNodePoolFree(
   HB_DOCK_NODE_POOL * pPool,
   HB_DOCK_NODE * pNode );

void hbDockNodePoolDestroy(
   HB_DOCK_NODE_POOL * pPool );

#ifdef __cplusplus
}
#endif

#endif