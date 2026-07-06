#include "hbdocktreecount.h"

int hbDockTreeCountLeaves(
   HB_DOCK_NODE * pRoot )
{
   if( pRoot == NULL )
      return 0;

   if( pRoot->Type == HB_DOCK_NODE_LEAF )
      return 1;

   return
      hbDockTreeCountLeaves(
         pRoot->First ) +
      hbDockTreeCountLeaves(
         pRoot->Second );
}

int hbDockTreeCountSplits(
   HB_DOCK_NODE * pRoot )
{
   if( pRoot == NULL )
      return 0;

   if( pRoot->Type == HB_DOCK_NODE_LEAF )
      return 0;

   return
      1 +
      hbDockTreeCountSplits(
         pRoot->First ) +
      hbDockTreeCountSplits(
         pRoot->Second );
}