#include <stdlib.h>
#include <string.h>

#include "hbdocklayouttree.h"

BOOL hbDockLayoutTreeInit(
      HB_DOCK_LAYOUT_TREE * pTree )
{
   memset(
      pTree,
      0,
      sizeof( *pTree ) );

   return TRUE;
}

static void hbDockLayoutFreeNode(
      HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return;

   hbDockLayoutFreeNode(
      pNode->First );

   hbDockLayoutFreeNode(
      pNode->Second );

   free(
      pNode );
}

void hbDockLayoutTreeDone(
      HB_DOCK_LAYOUT_TREE * pTree )
{
   hbDockLayoutFreeNode(
      pTree->Root );

   pTree->Root = NULL;
}