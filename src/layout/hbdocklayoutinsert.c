#include "hbdocklayoutinsert.h"
#include "hbdocklayoutnodecreate.h"
#include "hbdockcontainer.h"

BOOL hbDockLayoutInsertRoot(
      HB_DOCK_LAYOUT_TREE * pTree,
      HB_DOCK_CONTAINER * pContainer )
{
   if( pTree->Root )
      return FALSE;

   pTree->Root =
      hbDockLayoutCreateLeaf( pContainer );

   return pTree->Root != NULL;
}

BOOL hbDockLayoutSplitLeaf(
      HB_DOCK_LAYOUT_NODE * pLeaf,
      HB_DOCK_CONTAINER * pNewContainer,
      HB_LAYOUT_NODE_TYPE SplitType )
{
   HB_DOCK_LAYOUT_NODE * pOld;
   HB_DOCK_LAYOUT_NODE * pNew;

   if( pLeaf == NULL )
      return FALSE;

   pOld = hbDockLayoutCreateLeaf(
      pLeaf->pContainer );

   pNew = hbDockLayoutCreateLeaf(
      pNewContainer );

   if( pOld == NULL || pNew == NULL )
      return FALSE;

   pLeaf->Type = SplitType;

   pLeaf->First = pOld;
   pLeaf->Second = pNew;

   pOld->Parent = pLeaf;
   pNew->Parent = pLeaf;

   pLeaf->pContainer = NULL;

   return TRUE;
}