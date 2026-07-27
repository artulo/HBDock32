#include <windows.h>

#include "hbdocklayoutsplitcontainer.h"
#include "hbdockcontainer.h"
#include "hbdocklayoutnodecreate.h"


BOOL hbDockLayoutSplitContainer(
      HB_DOCK_LAYOUT_NODE * pNode,
      BOOL Vertical )
{
   HB_DOCK_CONTAINER * pOld;
   HB_DOCK_CONTAINER * pSecond;


   if( pNode == NULL )
      return FALSE;


   pOld = pNode->pContainer;


   if( pOld == NULL )
      return FALSE;


   /*
    * Nota de estabilizacion (Etapa 2): la version anterior reservaba
    * pFirst con calloc()/free() (el resto del proyecto usa siempre
    * LocalAlloc/LocalFree para HB_DOCK_CONTAINER, ver hbdockmanagerdock.c
    * y hbdockdockoperation.c) y ademas copiaba *pFirst = *pOld, lo que
    * dejaba a pFirst->TabGroup.Tabs apuntando a la MISMA memoria que
    * pOld->TabGroup.Tabs (alias peligroso: liberar uno deja al otro con
    * un puntero colgante). La solucion correcta es simplemente reusar
    * pOld como el primer hijo -- no hace falta copiarlo ni reservarlo
    * de nuevo.
    */

   pSecond =
      ( HB_DOCK_CONTAINER * )
      LocalAlloc(
         LPTR,
         sizeof( HB_DOCK_CONTAINER ) );

   if( pSecond == NULL )
      return FALSE;


   /*
    * Crear segundo contenedor vacío
    */

   if( !hbDockContainerCreate(
          pSecond,
          NULL ) )
   {
      LocalFree( pSecond );
      return FALSE;
   }


   /*
    * Convertir nodo hoja en split. El contenedor original (pOld) pasa
    * a ser el primer hijo tal cual, sin copiarlo.
    */

   pNode->pContainer = NULL;


   pNode->First =
      hbDockLayoutNodeCreateLeaf(
         pOld );


   pNode->Second =
      hbDockLayoutNodeCreateLeaf(
         pSecond );


   if( pNode->First == NULL ||
       pNode->Second == NULL )
   {
      /* pOld sigue siendo propiedad del arbol (no se reservo aqui);
       * solo liberamos lo que sí reservamos en esta funcion. */
      hbDockContainerDestroy( pSecond );
      LocalFree( pSecond );
      return FALSE;
   }


   pNode->Ratio = 0.5f;


   pNode->Type =
      Vertical ?
      HB_LAYOUT_VERTICAL :
      HB_LAYOUT_HORIZONTAL;


   return TRUE;
}