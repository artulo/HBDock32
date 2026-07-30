#include "hbdocklayoutinsertpanel.h"

#include "hbdocklayoutnodecreate.h"

BOOL hbDockLayoutInsertPanel(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pTarget,
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_SITE Site )
{
   HB_DOCK_LAYOUT_NODE * pLeaf;
   HB_DOCK_LAYOUT_NODE * pSplit;
   HB_DOCK_LAYOUT_NODE * pOldParent;

   if( pTree == NULL )
      return FALSE;

   if( pContainer == NULL )
      return FALSE;

   pLeaf =
      hbDockLayoutNodeCreateLeaf(
         pContainer );

   if( pLeaf == NULL )
      return FALSE;

   if( pTree->Root == NULL )
   {
      pTree->Root = pLeaf;
      return TRUE;
   }

   if( pTarget == NULL )
      pTarget = pTree->Root;

   /*
    * Etapa 20: guardar el padre VIEJO de pTarget antes de crear el
    * split -- hbDockLayoutNodeCreateSplit reasigna pTarget->Parent
    * para que apunte al nuevo split, asi que despues de esa llamada
    * ya es tarde para leerlo. Sin este guardado (y el reconectado de
    * mas abajo), insertar relativo a un nodo que NO sea la raiz
    * dejaba el split nuevo huerfano: el padre viejo de pTarget seguia
    * apuntando a pTarget directamente, nunca al split -- el nodo
    * nuevo quedaba fuera del arbol, inalcanzable desde la raiz.
    * Enmascarado hasta ahora porque todo llamador pasaba siempre la
    * raiz como target (donde este caso no aplica, ver el manejo
    * existente de pTree->Root == pTarget mas abajo).
    */
   pOldParent = pTarget->Parent;

   switch( Site )
   {
      case HB_DOCKSITE_LEFT:

         pSplit =
            hbDockLayoutNodeCreateSplit(
               HB_LAYOUT_HORIZONTAL,
               pLeaf,
               pTarget );
         break;

      case HB_DOCKSITE_TOP:

         pSplit =
            hbDockLayoutNodeCreateSplit(
               HB_LAYOUT_VERTICAL,
               pLeaf,
               pTarget );
         break;

      case HB_DOCKSITE_RIGHT:

         pSplit =
            hbDockLayoutNodeCreateSplit(
               HB_LAYOUT_HORIZONTAL,
               pTarget,
               pLeaf );
         break;

      case HB_DOCKSITE_BOTTOM:

         pSplit =
            hbDockLayoutNodeCreateSplit(
               HB_LAYOUT_VERTICAL,
               pTarget,
               pLeaf );
         break;

      default:
         return FALSE;
   }

   if( pSplit == NULL )
      return FALSE;

   /*
    * Etapa 49: pedido explicito -- poder fijar el ancho/alto de un
    * panel al acoplarlo (por ejemplo, "Explorador" siempre a 250px),
    * sin que tenga que repartirse 50/50 con su hermano, dejando el
    * resto como area central de trabajo de la aplicacion. Antes de
    * esto, hbDockLayoutNodeCreateSplit siempre fijaba Ratio=0.5f sin
    * excepcion -- DockSize (ver hbDockPanelSetDockSize) existia pero
    * solo se usaba para el ancho/alto de la franja de autohide, nunca
    * para el acoplado normal.
    *
    * Se usa el rect ACTUAL de pTarget (el nodo existente que se esta
    * dividiendo) para convertir el pixel deseado en un ratio -- es
    * una aproximacion INICIAL, no un tamaño fijo permanente: como el
    * resto del sistema es proporcional (Ratio), un resize posterior
    * de la ventana va a escalar este panel proporcionalmente junto
    * con los demas, no mantenerlo exactamente en esos pixeles. Sin
    * DockSize seteado (0,0 por defecto), el comportamiento no cambia
    * -- sigue siendo 0.5.
    */
   if( pContainer->TabGroup.pPanel != NULL )
   {
      SIZE DockSize;
      int nTargetSize;
      float Ratio;

      DockSize =
         pContainer->TabGroup.pPanel->DockSize;

      switch( Site )
      {
         case HB_DOCKSITE_LEFT:

            if( DockSize.cx > 0 )
            {
               nTargetSize =
                  pTarget->Rect.right -
                  pTarget->Rect.left;

               if( nTargetSize > 0 )
               {
                  Ratio =
                     ( float ) DockSize.cx /
                     ( float ) nTargetSize;

                  if( Ratio > 0.0f && Ratio < 1.0f )
                     pSplit->Ratio = Ratio;
               }
            }
            break;

         case HB_DOCKSITE_RIGHT:

            if( DockSize.cx > 0 )
            {
               nTargetSize =
                  pTarget->Rect.right -
                  pTarget->Rect.left;

               if( nTargetSize > 0 )
               {
                  Ratio =
                     1.0f -
                     ( ( float ) DockSize.cx /
                       ( float ) nTargetSize );

                  if( Ratio > 0.0f && Ratio < 1.0f )
                     pSplit->Ratio = Ratio;
               }
            }
            break;

         case HB_DOCKSITE_TOP:

            if( DockSize.cy > 0 )
            {
               nTargetSize =
                  pTarget->Rect.bottom -
                  pTarget->Rect.top;

               if( nTargetSize > 0 )
               {
                  Ratio =
                     ( float ) DockSize.cy /
                     ( float ) nTargetSize;

                  if( Ratio > 0.0f && Ratio < 1.0f )
                     pSplit->Ratio = Ratio;
               }
            }
            break;

         case HB_DOCKSITE_BOTTOM:

            if( DockSize.cy > 0 )
            {
               nTargetSize =
                  pTarget->Rect.bottom -
                  pTarget->Rect.top;

               if( nTargetSize > 0 )
               {
                  Ratio =
                     1.0f -
                     ( ( float ) DockSize.cy /
                       ( float ) nTargetSize );

                  if( Ratio > 0.0f && Ratio < 1.0f )
                     pSplit->Ratio = Ratio;
               }
            }
            break;

         default:
            break;
      }
   }

   if( pOldParent == NULL )
   {
      pTree->Root = pSplit;
   }
   else
   {
      pSplit->Parent = pOldParent;

      if( pOldParent->First == pTarget )
         pOldParent->First = pSplit;
      else
         pOldParent->Second = pSplit;
   }

   return TRUE;
}