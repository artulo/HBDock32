#include <stdlib.h>

#include "hbdocktree.h"

static void hbDockTreeLayoutNode(
   HB_DOCK_NODE * pNode,
   const RECT * pRect )
{
   RECT rc1;
   RECT rc2;
   int pos;

   if( pNode == NULL )
      return;

   pNode->Rect = *pRect;

   if( pNode->Type == HB_DOCK_NODE_LEAF )
   {
      if( pNode->Panel != NULL )
         pNode->Panel->Rect = *pRect;

      return;
   }

   pos = pNode->SplitPos;

   if( pos <= 0 )
   {
      if( pNode->Type == HB_DOCK_NODE_SPLIT_H )
         pos = ( pRect->right - pRect->left ) / 2;
      else
         pos = ( pRect->bottom - pRect->top ) / 2;
   }

   rc1 = *pRect;
   rc2 = *pRect;

   if( pNode->Type == HB_DOCK_NODE_SPLIT_H )
   {
      rc1.right = rc1.left + pos;
      rc2.left = rc1.right + pNode->SplitterSize;
   }
   else
   {
      rc1.bottom = rc1.top + pos;
      rc2.top = rc1.bottom + pNode->SplitterSize;
   }

   hbDockTreeLayoutNode(
      pNode->First,
      &rc1 );

   hbDockTreeLayoutNode(
      pNode->Second,
      &rc2 );
}

HB_DOCK_NODE * hbDockNodeNewLeaf(
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_NODE * pNode;

   pNode = ( HB_DOCK_NODE * ) calloc(
      1,
      sizeof( HB_DOCK_NODE ) );

   if( pNode == NULL )
      return NULL;

   pNode->Type = HB_DOCK_NODE_LEAF;
   pNode->Panel = pPanel;
   pNode->SplitterSize = 4;

   return pNode;
}

HB_DOCK_NODE * hbDockNodeNewSplit(
   HB_DOCK_NODE_TYPE Type,
   HB_DOCK_NODE * pFirst,
   HB_DOCK_NODE * pSecond )
{
   HB_DOCK_NODE * pNode;

   pNode = ( HB_DOCK_NODE * ) calloc(
      1,
      sizeof( HB_DOCK_NODE ) );

   if( pNode == NULL )
      return NULL;

   pNode->Type = Type;
   pNode->First = pFirst;
   pNode->Second = pSecond;
   pNode->SplitterSize = 4;

   if( pFirst != NULL )
      pFirst->Parent = pNode;

   if( pSecond != NULL )
      pSecond->Parent = pNode;

   return pNode;
}

void hbDockNodeDelete(
   HB_DOCK_NODE * pNode )
{
   if( pNode == NULL )
      return;

   hbDockNodeDelete(
      pNode->First );

   hbDockNodeDelete(
      pNode->Second );

   free(
      pNode );
}

void hbDockTreeLayout(
   HB_DOCK_NODE * pNode,
   const RECT * pRect )
{
   if( pNode == NULL || pRect == NULL )
      return;

   hbDockTreeLayoutNode(
      pNode,
      pRect );
}

HB_DOCK_PANEL * hbDockTreeHitTest(
   HB_DOCK_NODE * pNode,
   POINT pt )
{
   HB_DOCK_PANEL * pPanel;

   if( pNode == NULL )
      return NULL;

   if( !PtInRect(
         &pNode->Rect,
         pt ) )
      return NULL;

   if( pNode->Type == HB_DOCK_NODE_LEAF )
      return pNode->Panel;

   pPanel = hbDockTreeHitTest(
      pNode->First,
      pt );

   if( pPanel != NULL )
      return pPanel;

   return hbDockTreeHitTest(
      pNode->Second,
      pt );
}