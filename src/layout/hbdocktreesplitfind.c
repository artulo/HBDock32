#include "hbdocktreesplitfind.h"

static void hbDockNodeSplitterRect(
   HB_DOCK_NODE * pNode,
   RECT * pRect )
{
   *pRect = pNode->Rect;

   if( pNode->Type == HB_DOCK_NODE_SPLIT_H )
   {
      pRect->left  = pNode->Rect.left + pNode->SplitPos;
      pRect->right = pRect->left + pNode->SplitterSize;
   }
   else
   {
      pRect->top    = pNode->Rect.top + pNode->SplitPos;
      pRect->bottom = pRect->top + pNode->SplitterSize;
   }
}

HB_DOCK_NODE * hbDockTreeFindSplitterAt(
   HB_DOCK_NODE * pNode,
   POINT pt )
{
   RECT rc;
   HB_DOCK_NODE * pFound;

   if( pNode == NULL )
      return NULL;

   if( pNode->Type == HB_DOCK_NODE_LEAF )
      return NULL;

   hbDockNodeSplitterRect(
      pNode,
      &rc );

   if( PtInRect( &rc, pt ) )
      return pNode;

   pFound = hbDockTreeFindSplitterAt(
      pNode->First,
      pt );

   if( pFound != NULL )
      return pFound;

   return hbDockTreeFindSplitterAt(
      pNode->Second,
      pt );
}
