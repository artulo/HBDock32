#include <windows.h>

#include "hbdocklayouthittest.h"

static HB_DOCK_LAYOUT_NODE *
hbDockLayoutHitNode(
   HB_DOCK_LAYOUT_NODE * pNode,
   POINT pt )
{
   HB_DOCK_LAYOUT_NODE * pHit;

   if( pNode == NULL )
      return NULL;

   if( !PtInRect(
            &pNode->Rect,
            pt ) )
      return NULL;

   if( pNode->Type == HB_LAYOUT_LEAF )
      return pNode;

   pHit =
      hbDockLayoutHitNode(
         pNode->First,
         pt );

   if( pHit != NULL )
      return pHit;

   return
      hbDockLayoutHitNode(
         pNode->Second,
         pt );
}

HB_DOCK_LAYOUT_NODE *
hbDockLayoutHitTest(
   HB_DOCK_LAYOUT_TREE * pTree,
   POINT pt )
{
   if( pTree == NULL )
      return NULL;

   return
      hbDockLayoutHitNode(
         pTree->Root,
         pt );
}