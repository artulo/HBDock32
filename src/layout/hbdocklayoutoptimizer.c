#include "hbdocklayoutoptimizer.h"

static BOOL hbOptimizeNode(
      HB_DOCK_LAYOUT_NODE * pNode );

BOOL hbDockLayoutOptimize(
      HB_DOCK_LAYOUT_TREE * pTree )
{
   if( pTree == NULL )
      return FALSE;

   if( pTree->Root == NULL )
      return TRUE;

   return hbOptimizeNode(
      pTree->Root );
}

static BOOL hbOptimizeNode(
      HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return FALSE;

   return TRUE;
}