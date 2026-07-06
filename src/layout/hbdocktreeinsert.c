#include "hbdocktreeinsert.h"

static HB_DOCK_NODE * hbDockInsertNode(
   HB_DOCK_NODE * pTarget,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_NODE_TYPE Type,
   int Before )
{
   HB_DOCK_NODE * pLeaf;
   HB_DOCK_NODE * pSplit;

   if( pTarget == NULL )
      return NULL;

   pLeaf = hbDockNodeNewLeaf(
      pPanel );

   if( pLeaf == NULL )
      return NULL;

   if( Before )
      pSplit = hbDockNodeNewSplit(
         Type,
         pLeaf,
         pTarget );
   else
      pSplit = hbDockNodeNewSplit(
         Type,
         pTarget,
         pLeaf );

   if( pSplit == NULL )
   {
      hbDockNodeDelete(
         pLeaf );
      return NULL;
   }

   pSplit->SplitPos = 200;
   pSplit->SplitterSize = 4;

   return pSplit;
}

HB_DOCK_NODE * hbDockTreeInsertLeft(
   HB_DOCK_NODE * pTarget,
   HB_DOCK_PANEL * pPanel )
{
   return hbDockInsertNode(
      pTarget,
      pPanel,
      HB_DOCK_NODE_SPLIT_H,
      1 );
}

HB_DOCK_NODE * hbDockTreeInsertRight(
   HB_DOCK_NODE * pTarget,
   HB_DOCK_PANEL * pPanel )
{
   return hbDockInsertNode(
      pTarget,
      pPanel,
      HB_DOCK_NODE_SPLIT_H,
      0 );
}

HB_DOCK_NODE * hbDockTreeInsertTop(
   HB_DOCK_NODE * pTarget,
   HB_DOCK_PANEL * pPanel )
{
   return hbDockInsertNode(
      pTarget,
      pPanel,
      HB_DOCK_NODE_SPLIT_V,
      1 );
}

HB_DOCK_NODE * hbDockTreeInsertBottom(
   HB_DOCK_NODE * pTarget,
   HB_DOCK_PANEL * pPanel )
{
   return hbDockInsertNode(
      pTarget,
      pPanel,
      HB_DOCK_NODE_SPLIT_V,
      0 );
}