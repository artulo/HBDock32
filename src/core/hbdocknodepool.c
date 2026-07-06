#include <stdlib.h>
#include <string.h>

#include "hbdocknodepool.h"

void hbDockNodePoolInit(
   HB_DOCK_NODE_POOL * pPool )
{
   pPool->FreeList = NULL;
}

HB_DOCK_NODE * hbDockNodePoolAlloc(
   HB_DOCK_NODE_POOL * pPool )
{
   HB_DOCK_NODE * pNode;

   if( pPool->FreeList != NULL )
   {
      pNode = pPool->FreeList;
      pPool->FreeList = pNode->First;

      memset(
         pNode,
         0,
         sizeof( HB_DOCK_NODE ) );

      return pNode;
   }

   return ( HB_DOCK_NODE * )
      calloc(
         1,
         sizeof( HB_DOCK_NODE ) );
}

void hbDockNodePoolFree(
   HB_DOCK_NODE_POOL * pPool,
   HB_DOCK_NODE * pNode )
{
   if( pNode == NULL )
      return;

   pNode->First = pPool->FreeList;
   pPool->FreeList = pNode;
}

void hbDockNodePoolDestroy(
   HB_DOCK_NODE_POOL * pPool )
{
   HB_DOCK_NODE * pNode;
   HB_DOCK_NODE * pNext;

   pNode = pPool->FreeList;

   while( pNode != NULL )
   {
      pNext = pNode->First;
      free(
         pNode );
      pNode = pNext;
   }

   pPool->FreeList = NULL;
}