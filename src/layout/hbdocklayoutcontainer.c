#include "hbdocklayoutcontainer.h"

void hbDockLayoutAttachContainer(
      HB_DOCK_LAYOUT_NODE * pNode,
      HB_DOCK_CONTAINER * pContainer )
{
   if( pNode == NULL )
      return;

   pNode->pContainer = pContainer;
}

HB_DOCK_CONTAINER *
hbDockLayoutGetContainer(
      const HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return NULL;

   return pNode->pContainer;
}