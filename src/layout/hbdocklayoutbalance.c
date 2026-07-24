#include <windows.h>

#include "hbdocklayoutbalance.h"

static int hbDockLayoutCountLeaves(
   HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return 0;

   if( pNode->Type == HB_LAYOUT_LEAF )
      return 1;

   return
      hbDockLayoutCountLeaves(
         pNode->First ) +
      hbDockLayoutCountLeaves(
         pNode->Second );
}

static void hbDockLayoutBalanceNode(
   HB_DOCK_LAYOUT_NODE * pNode )
{
   int nFirst;
   int nSecond;
   int nTotal;

   if( pNode == NULL )
      return;

   if( pNode->Type == HB_LAYOUT_LEAF )
      return;

   hbDockLayoutBalanceNode(
      pNode->First );

   hbDockLayoutBalanceNode(
      pNode->Second );

   nFirst =
      hbDockLayoutCountLeaves(
         pNode->First );

   nSecond =
      hbDockLayoutCountLeaves(
         pNode->Second );

   nTotal =
      nFirst + nSecond;

   if( nTotal == 0 )
      pNode->Ratio = 0.5;
   else
      pNode->Ratio =
         ( double ) nFirst /
         ( double ) nTotal;

   /*
    * Evita extremos que producen
    * layouts degenerados.
    */

   if( pNode->Ratio < 0.10 )
      pNode->Ratio = 0.10;

   if( pNode->Ratio > 0.90 )
      pNode->Ratio = 0.90;
}

void hbDockLayoutBalance(
   HB_DOCK_LAYOUT_TREE * pTree )
{
   if( pTree == NULL )
      return;

   hbDockLayoutBalanceNode(
      pTree->Root );
}