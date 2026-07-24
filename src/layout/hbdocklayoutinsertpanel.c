#include "hbdocklayoutinsertpanel.h"

#include "hbdocklayoutnodecreate.h"

BOOL hbDockLayoutInsertPanel(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pTarget,
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_SITE Site )
{
   HB_DOCK_LAYOUT_NODE * pLeaf;
   HB_DOCK_LAYOUT_NODE * pSplit;

   if( pTree == NULL )
      return FALSE;

   if( pContainer == NULL )
      return FALSE;

   pLeaf =
      hbDockLayoutNodeCreateLeaf(
         pContainer );

   if( pLeaf == NULL )
      return FALSE;

   if( pTree->Root == NULL )
   {
      pTree->Root = pLeaf;
      return TRUE;
   }

   if( pTarget == NULL )
      pTarget = pTree->Root;

   switch( Site )
   {
      case HB_DOCKSITE_LEFT:

         pSplit =
            hbDockLayoutNodeCreateSplit(
               HB_LAYOUT_VERTICAL,
               pLeaf,
               pTarget );
         break;

      case HB_DOCKSITE_TOP:

         pSplit =
            hbDockLayoutNodeCreateSplit(
               HB_LAYOUT_HORIZONTAL,
               pLeaf,
               pTarget );
         break;

      case HB_DOCKSITE_RIGHT:

         pSplit =
            hbDockLayoutNodeCreateSplit(
               HB_LAYOUT_VERTICAL,
               pTarget,
               pLeaf );
         break;

      case HB_DOCKSITE_BOTTOM:

         pSplit =
            hbDockLayoutNodeCreateSplit(
               HB_LAYOUT_HORIZONTAL,
               pTarget,
               pLeaf );
         break;

      default:
         return FALSE;
   }

   if( pSplit == NULL )
      return FALSE;

   if( pTree->Root == pTarget )
      pTree->Root = pSplit;

   return TRUE;
}