#include <stdlib.h>

#include "hbdocklayoutsplitcontainer.h"
#include "hbdockcontainer.h"
#include "hbdocklayoutnodecreate.h"


BOOL hbDockLayoutSplitContainer(
      HB_DOCK_LAYOUT_NODE * pNode,
      BOOL Vertical )
{
   HB_DOCK_CONTAINER * pOld;
   HB_DOCK_CONTAINER * pFirst;
   HB_DOCK_CONTAINER * pSecond;


   if( pNode == NULL )
      return FALSE;


   pOld = pNode->pContainer;


   if( pOld == NULL )
      return FALSE;


   pFirst =
      (HB_DOCK_CONTAINER *) calloc(
         1,
         sizeof(HB_DOCK_CONTAINER) );


   pSecond =
      (HB_DOCK_CONTAINER *) calloc(
         1,
         sizeof(HB_DOCK_CONTAINER) );


   if( pFirst == NULL || pSecond == NULL )
   {
      if( pFirst != NULL )
         free(pFirst);

      if( pSecond != NULL )
         free(pSecond);

      return FALSE;
   }


   /*
    * Copiar contenedor original
    */

   *pFirst = *pOld;


   /*
    * Crear segundo contenedor vacío
    */

   if( !hbDockContainerCreate(
          pSecond,
          NULL ) )
   {
      free(pFirst);
      free(pSecond);
      return FALSE;
   }


   /*
    * Convertir nodo hoja en split
    */

   pNode->pContainer = NULL;


   pNode->First =
      hbDockLayoutCreateLeaf(
         pFirst );


   pNode->Second =
      hbDockLayoutCreateLeaf(
         pSecond );


   if( pNode->First == NULL ||
       pNode->Second == NULL )
   {
      free(pFirst);
      free(pSecond);
      return FALSE;
   }


   pNode->Ratio = 0.5f;


   pNode->Type =
      Vertical ?
      HB_LAYOUT_VERTICAL :
      HB_LAYOUT_HORIZONTAL;


   return TRUE;
}