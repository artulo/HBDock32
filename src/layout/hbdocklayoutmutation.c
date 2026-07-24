#include <windows.h>
#include <stdlib.h>

#include "hbdocklayoutmutation.h"
#include "hbdocklayoutnodecreate.h"



static void hbDockLayoutDetachNode(
   HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return;


   if( pNode->Parent == NULL )
      return;


   if( pNode->Parent->First == pNode )
   {
      pNode->Parent->First = NULL;
   }
   else if( pNode->Parent->Second == pNode )
   {
      pNode->Parent->Second = NULL;
   }


   pNode->Parent = NULL;
}



BOOL hbDockLayoutRemoveNode(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pNode )
{
   HB_DOCK_LAYOUT_NODE * pParent;
   HB_DOCK_LAYOUT_NODE * pBrother;


   if( pTree == NULL ||
       pNode == NULL )
      return FALSE;


   pParent = pNode->Parent;


   /*
    * Si es raíz.
    */

   if( pParent == NULL )
   {
      if( pTree->Root == pNode )
      {
         pTree->Root = NULL;

         free(
            pNode );

         return TRUE;
      }

      return FALSE;
   }



   /*
    * Buscar hermano.
    */

   if( pParent->First == pNode )
   {
      pBrother =
         pParent->Second;
   }
   else
   {
      pBrother =
         pParent->First;
   }


   if( pBrother == NULL )
      return FALSE;



   /*
    * Reemplazar el padre por el hermano.
    */

   if( pParent->Parent == NULL )
   {
      pTree->Root = pBrother;

      pBrother->Parent = NULL;
   }
   else
   {
      pBrother->Parent =
         pParent->Parent;


      if( pParent->Parent->First == pParent )
      {
         pParent->Parent->First =
            pBrother;
      }
      else
      {
         pParent->Parent->Second =
            pBrother;
      }
   }



   free(
      pNode );


   free(
      pParent );


   return TRUE;
}



BOOL hbDockLayoutReplace(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pOld,
   HB_DOCK_LAYOUT_NODE * pNew )
{
   if( pTree == NULL ||
       pOld == NULL ||
       pNew == NULL )
      return FALSE;


   if( pOld->Parent == NULL )
   {
      pTree->Root = pNew;

      pNew->Parent = NULL;

      return TRUE;
   }


   pNew->Parent =
      pOld->Parent;


   if( pOld->Parent->First == pOld )
   {
      pOld->Parent->First =
         pNew;
   }
   else
   {
      pOld->Parent->Second =
         pNew;
   }


   return TRUE;
}