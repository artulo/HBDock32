#include <stdlib.h>

#include "hbdocklayoutremoveempty.h"



static HB_DOCK_LAYOUT_NODE * hbDockSibling(
   HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return NULL;

   if( pNode->Parent == NULL )
      return NULL;

   if( pNode->Parent->First == pNode )
      return pNode->Parent->Second;

   return pNode->Parent->First;
}



BOOL hbDockLayoutRemoveEmpty(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pLeaf )
{
   HB_DOCK_LAYOUT_NODE * pParent;
   HB_DOCK_LAYOUT_NODE * pBrother;

   if( pTree == NULL )
      return FALSE;

   if( pLeaf == NULL )
      return FALSE;

   if( pLeaf->Type != HB_LAYOUT_LEAF )
      return FALSE;

   /*
    * Sólo se eliminan hojas sin contenedor.
    */

   if( pLeaf->pContainer != NULL )
      return FALSE;

   pParent = pLeaf->Parent;

   /*
    * Era la raíz.
    */

   if( pParent == NULL )
   {
      pTree->Root = NULL;

      free(
         pLeaf );

      return TRUE;
   }

   pBrother =
      hbDockSibling(
         pLeaf );

   if( pBrother == NULL )
      return FALSE;

   /*
    * El abuelo pasa a apuntar al hermano.
    */

   if( pParent->Parent == NULL )
   {
      pTree->Root = pBrother;

      pBrother->Parent = NULL;
   }
   else
   {
      if( pParent->Parent->First == pParent )
         pParent->Parent->First = pBrother;
      else
         pParent->Parent->Second = pBrother;

      pBrother->Parent =
         pParent->Parent;
   }

   free(
      pLeaf );

   free(
      pParent );

   return TRUE;
}