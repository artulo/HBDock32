#include <stdlib.h>

#include "hbdockdockoperation.h"

HB_DOCK_NODE * hbDockInsertPanel(
   HB_DOCK_NODE * pTarget,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_SITE Site )
{
   HB_DOCK_NODE * pLeaf;
   HB_DOCK_NODE * pSplit;

   if( pTarget == NULL )
      return NULL;

   pLeaf = hbDockNodeNewLeaf(
      pPanel );

   if( pLeaf == NULL )
      return NULL;

   switch( Site )
   {
      case HB_DOCKSITE_LEFT:

         pSplit = hbDockNodeNewSplit(
            HB_DOCK_NODE_SPLIT_H,
            pLeaf,
            pTarget );
         break;

      case HB_DOCKSITE_RIGHT:

         pSplit = hbDockNodeNewSplit(
            HB_DOCK_NODE_SPLIT_H,
            pTarget,
            pLeaf );
         break;

      case HB_DOCKSITE_TOP:

         pSplit = hbDockNodeNewSplit(
            HB_DOCK_NODE_SPLIT_V,
            pLeaf,
            pTarget );
         break;

      case HB_DOCKSITE_BOTTOM:

         pSplit = hbDockNodeNewSplit(
            HB_DOCK_NODE_SPLIT_V,
            pTarget,
            pLeaf );
         break;

      default:

         hbDockNodeDelete(
            pLeaf );

         return pTarget;
   }

   pSplit->SplitPos = 200;

   return pSplit;
}