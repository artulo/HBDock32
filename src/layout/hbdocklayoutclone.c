#include <windows.h>
#include <stdlib.h>

#include "hbdocklayoutclone.h"
#include "hbdocklayoutnodecreate.h"


static HB_DOCK_LAYOUT_NODE * hbDockCloneNodeInternal(
   const HB_DOCK_LAYOUT_NODE * pSource,
   HB_DOCK_LAYOUT_NODE * pParent )
{
   HB_DOCK_LAYOUT_NODE * pNode;


   if( pSource == NULL )
      return NULL;



   if( pSource->Type == HB_LAYOUT_LEAF )
   {
      pNode =
         hbDockLayoutNodeCreateLeaf(
            pSource->pContainer );
   }
   else
   {
      pNode =
         hbDockLayoutNodeCreateSplit(
            pSource->Type,
            NULL,
            NULL );
   }



   if( pNode == NULL )
      return NULL;



   pNode->Parent =
      pParent;


   pNode->Ratio =
      pSource->Ratio;


   pNode->Rect =
      pSource->Rect;



   pNode->First =
      hbDockCloneNodeInternal(
         pSource->First,
         pNode );


   pNode->Second =
      hbDockCloneNodeInternal(
         pSource->Second,
         pNode );



   return pNode;
}



HB_DOCK_LAYOUT_NODE * hbDockLayoutCloneNode(
   const HB_DOCK_LAYOUT_NODE * pNode )
{
   return
      hbDockCloneNodeInternal(
         pNode,
         NULL );
}



BOOL hbDockLayoutCloneTree(
   const HB_DOCK_LAYOUT_TREE * pSource,
   HB_DOCK_LAYOUT_TREE * pDest )
{
   if( pSource == NULL )
      return FALSE;


   if( pDest == NULL )
      return FALSE;



   ZeroMemory(
      pDest,
      sizeof( HB_DOCK_LAYOUT_TREE ) );



   pDest->Root =
      hbDockCloneNodeInternal(
         pSource->Root,
         NULL );



   return TRUE;
}