#include "hbdocklayoutremovepanel.h"

#include "hbdocklayoutfindleaf.h"
#include "hbdocklayoutmutation.h"
#include "hbdocklayoutremoveempty.h"
#include "hbdocklayoutoptimizer.h"


BOOL hbDockLayoutRemovePanel(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_CONTAINER * pContainer )
{
   HB_DOCK_LAYOUT_NODE * pLeaf;


   if( pTree == NULL )
      return FALSE;


   if( pContainer == NULL )
      return FALSE;


   pLeaf =
      hbDockLayoutFindLeaf(
         pTree->Root,
         pContainer );


   if( pLeaf == NULL )
      return FALSE;


   /*
    * Desasociar el contenedor.
    */

   pLeaf->pContainer = NULL;


   /*
    * Eliminar nodos vacíos.
    */

   hbDockLayoutRemoveEmpty(
      pTree,
      pLeaf );


   /*
    * Optimizar árbol.
    */

   hbDockLayoutOptimize(
      pTree );


   if( pTree->Root != NULL )
      pTree->Root->Parent = NULL;


   return TRUE;
}