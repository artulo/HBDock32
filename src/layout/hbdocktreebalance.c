#include "hbdocktreebalance.h"

static void hbDockNormalize(
   HB_DOCK_NODE * pNode )
{
   if( pNode == NULL )
      return;

   if( pNode->Type != HB_DOCK_NODE_LEAF )
   {
      if( pNode->SplitPos <= 0 )
         pNode->SplitPos = 200;

      if( pNode->SplitterSize <= 0 )
         pNode->SplitterSize = 4;
   }

   hbDockNormalize(
      pNode->First );

   hbDockNormalize(
      pNode->Second );
}

void hbDockTreeNormalize(
   HB_DOCK_NODE * pRoot )
{
   hbDockNormalize(
      pRoot );
}