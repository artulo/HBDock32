#include "hbdocklayoutvalidate.h"

static BOOL ValidateNode(
      const HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return TRUE;

   if( pNode->Type != HB_LAYOUT_LEAF )
   {
      if( pNode->First == NULL )
         return FALSE;

      if( pNode->Second == NULL )
         return FALSE;
   }

   return
      ValidateNode(
         pNode->First ) &&
      ValidateNode(
         pNode->Second );
}

BOOL hbDockLayoutValidate(
      const HB_DOCK_LAYOUT_TREE * pTree )
{
   if( pTree == NULL )
      return FALSE;

   return ValidateNode(
      pTree->Root );
}