#include <stdlib.h>

#include "hbdocklayoutdestroy.h"


void hbDockLayoutDestroyNode(
   HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return;


   hbDockLayoutDestroyNode(
      pNode->First );


   hbDockLayoutDestroyNode(
      pNode->Second );


   free(
      pNode );
}



void hbDockLayoutDestroyTree(
   HB_DOCK_LAYOUT_TREE * pTree )
{
   if( pTree == NULL )
      return;


   hbDockLayoutDestroyNode(
      pTree->Root );


   pTree->Root = NULL;
}