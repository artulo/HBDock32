#include "hbdocklayoutinsertnode.h"

BOOL hbDockLayoutInsertNode(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pNode,
   UINT Side )
{
   (void)(Side);

   if( pTree->Root == NULL )
   {
      pTree->Root = pNode;
      return TRUE;
   }

   return FALSE;
}