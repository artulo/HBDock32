#include "hbdocklayoutfindleaf.h"

HB_DOCK_LAYOUT_NODE * hbDockLayoutFindLeaf(
   HB_DOCK_LAYOUT_NODE * pNode,
   HB_DOCK_CONTAINER * pContainer )
{
   HB_DOCK_LAYOUT_NODE * pFound;

   if( pNode == NULL )
      return NULL;

   if( pNode->Type == HB_LAYOUT_LEAF )
   {
      if( pNode->pContainer == pContainer )
         return pNode;

      return NULL;
   }

   pFound =
      hbDockLayoutFindLeaf(
         pNode->First,
         pContainer );

   if( pFound != NULL )
      return pFound;

   return hbDockLayoutFindLeaf(
      pNode->Second,
      pContainer );
}