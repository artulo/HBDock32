#include "hbdocklayoutfind.h"
#include "hbapi.h"

static HB_DOCK_LAYOUT_NODE *
hbDockFindRecursive(
   HB_DOCK_LAYOUT_NODE * pNode,
   HB_DOCK_CONTAINER * pContainer )
{
   HB_DOCK_LAYOUT_NODE * pFound;

   if( pNode == NULL )
      return NULL;

   if( pNode->Type == HB_LAYOUT_LEAF &&
       pNode->pContainer == pContainer )
      return pNode;

   pFound = hbDockFindRecursive(
      pNode->First,
      pContainer );

   if( pFound )
      return pFound;

   return hbDockFindRecursive(
      pNode->Second,
      pContainer );
}

HB_DOCK_LAYOUT_NODE *
hbDockLayoutFindContainer(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_CONTAINER * pContainer )
{
   if( pTree == NULL )
      return NULL;

   return hbDockFindRecursive(
      pTree->Root,
      pContainer );
}

HB_DOCK_LAYOUT_NODE *
hbDockLayoutFindPanel(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_PANEL * pPanel )
{
   HB_SYMBOL_UNUSED( pTree );
   HB_SYMBOL_UNUSED( pPanel );

   return NULL;
}