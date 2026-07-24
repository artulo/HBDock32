#include <windows.h>

#include "hbdocklayoutinsert.h"

#include "hbdocklayoutnodecreate.h"
#include "hbdocklayouttree.h"
#include "hbdockdocksite.h"



static HB_DOCK_LAYOUT_NODE * hbDockLayoutFindLeaf(
   HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return NULL;


   if( pNode->Type == HB_LAYOUT_LEAF )
      return pNode;


   if( pNode->First != NULL )
   {
      HB_DOCK_LAYOUT_NODE * pFound;

      pFound =
         hbDockLayoutFindLeaf(
            pNode->First );

      if( pFound != NULL )
         return pFound;
   }


   return hbDockLayoutFindLeaf(
      pNode->Second );
}



static void hbDockLayoutReplaceNode(
   HB_DOCK_LAYOUT_NODE * pOld,
   HB_DOCK_LAYOUT_NODE * pNew )
{
   if( pOld == NULL ||
       pNew == NULL )
      return;


   pNew->Parent =
      pOld->Parent;


   if( pOld->Parent != NULL )
   {
      if( pOld->Parent->First == pOld )
      {
         pOld->Parent->First = pNew;
      }
      else
      {
         pOld->Parent->Second = pNew;
      }
   }
}



BOOL hbDockLayoutInsertPanel(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_PANEL * pPanel,
   int Side )
{
   HB_DOCK_LAYOUT_NODE * pLeaf;
   HB_DOCK_LAYOUT_NODE * pNewLeaf;
   HB_DOCK_LAYOUT_NODE * pSplit;


   if( pTree == NULL )
      return FALSE;


   if( pPanel == NULL )
      return FALSE;


   pNewLeaf =
      hbDockLayoutNodeCreateLeaf(
         pPanel );


   if( pNewLeaf == NULL )
      return FALSE;

 
   /*
    * Árbol vacío:
    * el primer panel se convierte en raíz.
    */

   if( pTree->Root == NULL )
   {
      pTree->Root = pNewLeaf;

      return TRUE;
   }


   pLeaf =
      hbDockLayoutFindLeaf(
         pTree->Root );


   if( pLeaf == NULL )
      return FALSE;


   if( Side == HB_DOCKSITE_LEFT ||
       Side == HB_DOCKSITE_RIGHT )
   {
      pSplit =
         hbDockLayoutNodeCreateSplit(
            HB_LAYOUT_HORIZONTAL,
            pLeaf,
            pNewLeaf );
   }
   else
   {
      pSplit =
         hbDockLayoutNodeCreateSplit(
            HB_LAYOUT_VERTICAL,
            pLeaf,
            pNewLeaf );
   }


   if( pSplit == NULL )
      return FALSE;


   hbDockLayoutReplaceNode(
      pLeaf,
      pSplit );


   if( pSplit->Parent == NULL )
      pTree->Root = pSplit;


   return TRUE;
}