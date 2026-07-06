#include <stdlib.h>

#include "hbdocktreeremove.h"

HB_DOCK_NODE * hbDockTreeRemoveNode(
   HB_DOCK_NODE * pRoot,
   HB_DOCK_NODE * pNode )
{
   HB_DOCK_NODE * pParent;
   HB_DOCK_NODE * pKeep;

   if( pRoot == NULL || pNode == NULL )
      return pRoot;

   if( pRoot == pNode )
   {
      free( pRoot );
      return NULL;
   }

   pParent = pNode->Parent;

   if( pParent == NULL )
      return pRoot;

   if( pParent->First == pNode )
      pKeep = pParent->Second;
   else
      pKeep = pParent->First;

   if( pParent->Parent != NULL )
   {
      if( pParent->Parent->First == pParent )
         pParent->Parent->First = pKeep;
      else
         pParent->Parent->Second = pKeep;

      pKeep->Parent = pParent->Parent;
   }
   else
   {
      pKeep->Parent = NULL;
      pRoot = pKeep;
   }

   free( pNode );
   free( pParent );

   return pRoot;
}