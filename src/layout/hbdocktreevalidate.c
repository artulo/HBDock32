#include "hbdocktreevalidate.h"

static int hbDockValidateNode(
   HB_DOCK_NODE * pNode )
{
   if( pNode == NULL )
      return 1;

   if( pNode->Type == HB_DOCK_NODE_LEAF )
   {
      if( pNode->First != NULL )
         return 0;

      if( pNode->Second != NULL )
         return 0;

      return 1;
   }

   if( pNode->First == NULL )
      return 0;

   if( pNode->Second == NULL )
      return 0;

   if( pNode->First->Parent != pNode )
      return 0;

   if( pNode->Second->Parent != pNode )
      return 0;

   return
      hbDockValidateNode(
         pNode->First ) &&
      hbDockValidateNode(
         pNode->Second );
}

int hbDockTreeValidate(
   HB_DOCK_NODE * pRoot )
{
   return hbDockValidateNode(
      pRoot );
}