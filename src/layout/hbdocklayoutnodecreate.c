#include <stdlib.h>
#include <string.h>

#include "hbdocklayoutnodecreate.h"

HB_DOCK_LAYOUT_NODE *
hbDockLayoutCreateLeaf(
      HWND hDock )
{
   HB_DOCK_LAYOUT_NODE * pNode;

   pNode =
      (HB_DOCK_LAYOUT_NODE*)
      calloc(
         1,
         sizeof( HB_DOCK_LAYOUT_NODE ) );

   if( pNode == NULL )
      return NULL;

   pNode->Type = HB_LAYOUT_LEAF;
   pNode->Ratio = 0.5f;
   pNode->hDockWindow = hDock;

   return pNode;
}

HB_DOCK_LAYOUT_NODE *
hbDockLayoutCreateSplit(
      HB_LAYOUT_NODE_TYPE Type )
{
   HB_DOCK_LAYOUT_NODE * pNode;

   pNode =
      (HB_DOCK_LAYOUT_NODE*)
      calloc(
         1,
         sizeof( HB_DOCK_LAYOUT_NODE ) );

   if( pNode == NULL )
      return NULL;

   pNode->Type = Type;
   pNode->Ratio = 0.5f;

   return pNode;
}