#include "hbdocklayoutinsertnode.h"
#include "hbapi.h"

BOOL hbDockLayoutInsertNode(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pNode,
   UINT Side )
{
   HB_SYMBOL_UNUSED( Side );

   if( pTree->Root == NULL )
   {
      pTree->Root = pNode;
      return TRUE;
   }

   return FALSE;
}