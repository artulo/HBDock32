#include "hbdockleaf.h"

int hbDockLeafCount(
   HB_DOCK_NODE * pRoot )
{
   if( pRoot == NULL )
      return 0;

   if( pRoot->Type == HB_DOCK_NODE_LEAF )
      return 1;

   return
      hbDockLeafCount(
         pRoot->First ) +
      hbDockLeafCount(
         pRoot->Second );
}

HB_DOCK_NODE * hbDockLeafFirst(
   HB_DOCK_NODE * pRoot )
{
   if( pRoot == NULL )
      return NULL;

   while( pRoot->Type != HB_DOCK_NODE_LEAF )
      pRoot = pRoot->First;

   return pRoot;
}

HB_DOCK_NODE * hbDockLeafLast(
   HB_DOCK_NODE * pRoot )
{
   if( pRoot == NULL )
      return NULL;

   while( pRoot->Type != HB_DOCK_NODE_LEAF )
      pRoot = pRoot->Second;

   return pRoot;
}