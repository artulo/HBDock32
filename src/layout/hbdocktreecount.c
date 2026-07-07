#include "hbdocktreecount.h"

int hbDockTreeNodeCount(
   HB_DOCK_NODE * pRoot )
{
   if( pRoot == NULL )
      return 0;

   return
      1 +
      hbDockTreeNodeCount(
         pRoot->First ) +
      hbDockTreeNodeCount(
         pRoot->Second );
}

int hbDockTreeLeafCount(
   HB_DOCK_NODE * pRoot )
{
   if( pRoot == NULL )
      return 0;

   if( pRoot->Type ==
       HB_DOCK_NODE_LEAF )
      return 1;

   return
      hbDockTreeLeafCount(
         pRoot->First ) +
      hbDockTreeLeafCount(
         pRoot->Second );
}

int hbDockTreeSplitCount(
   HB_DOCK_NODE * pRoot )
{
   if( pRoot == NULL )
      return 0;

   if( pRoot->Type ==
       HB_DOCK_NODE_LEAF )
      return 0;

   return
      1 +
      hbDockTreeSplitCount(
         pRoot->First ) +
      hbDockTreeSplitCount(
         pRoot->Second );
}