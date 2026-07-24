#include <windows.h>

#include "hbdocklayoutcopy.h"
#include "hbdocklayoutnodecreate.h"
 
HB_DOCK_LAYOUT_NODE * hbDockLayoutCopyNode(
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

   pNode->Parent = pParent;

   pNode->Ratio = pSource->Ratio;

   pNode->Rect = pSource->Rect;

   pNode->First =
      hbDockLayoutCopyNode(
         pSource->First,
         pNode );

   pNode->Second =
      hbDockLayoutCopyNode(
         pSource->Second,
         pNode );

   return pNode;
}