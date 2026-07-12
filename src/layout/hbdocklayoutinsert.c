#include "hbdocklayoutinsert.h"
#include "hbdocklayoutnodecreate.h"

BOOL hbDockLayoutInsertRoot(
      HB_DOCK_LAYOUT_TREE * pTree,
      HWND hDock )
{
   if( pTree->Root )
      return FALSE;

   pTree->Root =
      hbDockLayoutCreateLeaf(
         hDock );

   return
      pTree->Root != NULL;
}

BOOL hbDockLayoutSplitLeaf(
      HB_DOCK_LAYOUT_NODE * pLeaf,
      HWND hNewDock,
      HB_LAYOUT_NODE_TYPE SplitType )
{
   HB_DOCK_LAYOUT_NODE * pOld;
   HB_DOCK_LAYOUT_NODE * pNew;

   if( pLeaf == NULL )
      return FALSE;

   pOld =
      hbDockLayoutCreateLeaf(
         pLeaf->hDockWindow );

   pNew =
      hbDockLayoutCreateLeaf(
         hNewDock );

   pLeaf->Type = SplitType;

   pLeaf->First = pOld;
   pLeaf->Second = pNew;

   pOld->Parent = pLeaf;
   pNew->Parent = pLeaf;

   pLeaf->hDockWindow = NULL;

   return TRUE;
}