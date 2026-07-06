#include "hbdocktreeclone.h"

HB_DOCK_NODE * hbDockTreeClone(
   HB_DOCK_NODE * pRoot )
{
   HB_DOCK_NODE * pNew;

   if( pRoot == NULL )
      return NULL;

   if( pRoot->Type == HB_DOCK_NODE_LEAF )
   {
      pNew = hbDockNodeNewLeaf(
         pRoot->Panel );
   }
   else
   {
      pNew = hbDockNodeNewSplit(
         pRoot->Type,
         hbDockTreeClone(
            pRoot->First ),
         hbDockTreeClone(
            pRoot->Second ) );

      pNew->SplitPos =
         pRoot->SplitPos;

      pNew->SplitterSize =
         pRoot->SplitterSize;
   }

   pNew->Rect = pRoot->Rect;

   return pNew;
}