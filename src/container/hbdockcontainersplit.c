#include <windows.h>

#include "hbdockcontainersplit.h"

#include "hbdocklayouttree.h"
#include "hbdocklayoutnodecreate.h"



BOOL hbDockContainerSplit(
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_CONTAINER * pNewContainer,
   int Orientation )
{
   HB_DOCK_LAYOUT_NODE * pFirst;
   HB_DOCK_LAYOUT_NODE * pSecond;
   HB_DOCK_LAYOUT_NODE * pSplit;


   if( pContainer == NULL )
      return FALSE;


   if( pNewContainer == NULL )
      return FALSE;


   /*
    * Crear hojas.
    */

   pFirst =
      hbDockLayoutCreateLeaf(
         pContainer );


   if( pFirst == NULL )
      return FALSE;


   pSecond =
      hbDockLayoutCreateLeaf(
         pNewContainer );


   if( pSecond == NULL )
      return FALSE;


   /*
    * Crear nodo split.
    */

   if( Orientation == 0 )
   {
      pSplit =
         hbDockLayoutCreateSplit(
            HB_LAYOUT_HORIZONTAL );
   }
   else
   {
      pSplit =
         hbDockLayoutCreateSplit(
            HB_LAYOUT_VERTICAL );
   }


   if( pSplit == NULL )
      return FALSE;


   /*
    * Asociar hijos.
    */

   pSplit->First =
      pFirst;

   pSplit->Second =
      pSecond;


   pFirst->Parent =
      pSplit;

   pSecond->Parent =
      pSplit;


   pSplit->Ratio =
      0.5f;


   return TRUE;
}