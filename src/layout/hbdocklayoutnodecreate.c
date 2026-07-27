#include <stdlib.h>

#include "hbdocklayoutnodecreate.h"


HB_DOCK_LAYOUT_NODE * hbDockLayoutNodeCreateLeaf(
   HB_DOCK_CONTAINER * pContainer )
{
   HB_DOCK_LAYOUT_NODE * pNode;


   pNode =
      ( HB_DOCK_LAYOUT_NODE * ) calloc(
         1,
         sizeof( HB_DOCK_LAYOUT_NODE ) );


   if( pNode == NULL )
      return NULL;


   pNode->Type =
      HB_LAYOUT_LEAF;


   pNode->pContainer =
      pContainer;


   return pNode;
}



HB_DOCK_LAYOUT_NODE * hbDockLayoutNodeCreateSplit(
   HB_LAYOUT_NODE_TYPE Type,
   HB_DOCK_LAYOUT_NODE * pFirst,
   HB_DOCK_LAYOUT_NODE * pSecond )
{
   HB_DOCK_LAYOUT_NODE * pNode;


   pNode =
      ( HB_DOCK_LAYOUT_NODE * ) calloc(
         1,
         sizeof( HB_DOCK_LAYOUT_NODE ) );


   if( pNode == NULL )
      return NULL;


   pNode->Type =
      Type;


   pNode->First =
      pFirst;


   pNode->Second =
      pSecond;


   pNode->Ratio =
      0.5f;


   if( pFirst != NULL )
      pFirst->Parent = pNode;


   if( pSecond != NULL )
      pSecond->Parent = pNode;


   return pNode;
}