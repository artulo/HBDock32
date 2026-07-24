#include <stdlib.h>

#include "hbdocklayoutoptimizer.h"

static HB_DOCK_LAYOUT_NODE * hbDockOptimizeNode(
   HB_DOCK_LAYOUT_NODE * pNode )
{
   HB_DOCK_LAYOUT_NODE * pChild;

   if( pNode == NULL )
      return NULL;

   if( pNode->Type == HB_LAYOUT_LEAF )
      return pNode;

   pNode->First =
      hbDockOptimizeNode(
         pNode->First );

   pNode->Second =
      hbDockOptimizeNode(
         pNode->Second );

   /*
    * Ambos hijos eliminados
    */

   if( pNode->First == NULL &&
       pNode->Second == NULL )
   {
      free(
         pNode );

      return NULL;
   }

   /*
    * Sólo queda el hijo izquierdo
    */

   if( pNode->Second == NULL )
   {
      pChild =
         pNode->First;

      if( pChild != NULL )
         pChild->Parent =
            pNode->Parent;

      free(
         pNode );

      return pChild;
   }

   /*
    * Sólo queda el hijo derecho
    */

   if( pNode->First == NULL )
   {
      pChild =
         pNode->Second;

      if( pChild != NULL )
         pChild->Parent =
            pNode->Parent;

      free(
         pNode );

      return pChild;
   }

   /*
    * Actualizar padres
    */

   pNode->First->Parent =
      pNode;

   pNode->Second->Parent =
      pNode;

   return pNode;
}

void hbDockLayoutOptimize(
   HB_DOCK_LAYOUT_TREE * pTree )
{
   if( pTree == NULL )
      return;

   pTree->Root =
      hbDockOptimizeNode(
         pTree->Root );

   if( pTree->Root != NULL )
      pTree->Root->Parent = NULL;
}