#include <windows.h>

#include "hbdocklayoutrecalc.h"
#include "hbdocklayouttree.h"
#include "hbdockcontainer.h"
#include "hbdockcaption.h"

#define HBDOCK_SPLITTER_SIZE 4

/*
 * Nota de estabilizacion (Etapa 9): esta funcion ya calculaba
 * correctamente pNode->pContainer->Rect en cada nodo hoja (la
 * geometria del arbol es correcta, verificado en Etapa 2), pero
 * nunca movia la ventana real del panel activo -- hbDockPanelMoveWindow
 * (src/dock/hbdockpanelmove.c) existe y funciona pero no tenia NINGUN
 * llamador en todo el proyecto. En la practica esto significaba que,
 * aunque el arbol de docking calculara bien donde va cada panel, el
 * control real del usuario (un TBrowse, un GET, lo que sea) nunca se
 * movia ni redimensionaba para reflejarlo.
 *
 * Se reserva una franja de HBDOCK_CAPTION_HEIGHT arriba de cada
 * contenedor para el caption/tabs (el mismo alto que ya usa
 * hbDockHostFindCaptionAt en hbdockhost.c para el hit-test del
 * arrastre), y el resto se lo lleva la ventana del panel activo del
 * TabGroup.
 */

static void hbDockLayoutApplyContainer(
   HB_DOCK_CONTAINER * pContainer )
{
   HB_DOCK_PANEL * pPanel;
   RECT rc;
   UINT i;

   if( pContainer == NULL )
      return;

   pPanel = pContainer->TabGroup.pPanel;

   if( pPanel == NULL )
      return;

   /*
    * Nota de estabilizacion: si hay mas de un panel tabificado en
    * este contenedor, solo el activo (pContainer->TabGroup.pPanel)
    * se movia/mostraba mas abajo -- los demas (las otras pestañas)
    * nunca se ocultaban, asi que se quedaban visibles en pantalla
    * en su ULTIMA posicion conocida, superpuestos con cualquier
    * otra cosa. Confirmado con captura real (Rects): un panel
    * tabificado quedaba con un tamaño completamente viejo, de antes
    * de que el contenedor cambiara de forma. Se ocultan aca todas
    * las pestañas que no sean la activa.
    */
   for( i = 0; i < pContainer->TabGroup.Count; i++ )
   {
      HB_DOCK_PANEL * pOther;

      pOther = pContainer->TabGroup.Tabs[ i ].pPanel;

      if( pOther != NULL &&
          pOther != pPanel &&
          pOther->hWnd != NULL )
      {
         ShowWindow(
            pOther->hWnd,
            SW_HIDE );
      }
   }

   rc = pContainer->Rect;

   rc.top += HBDOCK_CAPTION_HEIGHT;

   if( rc.top > rc.bottom )
      rc.top = rc.bottom;

   pPanel->Rect = rc;

   if( pPanel->hWnd != NULL )
   {
      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );

      MoveWindow(
         pPanel->hWnd,
         rc.left,
         rc.top,
         rc.right - rc.left,
         rc.bottom - rc.top,
         TRUE );
   }
}

static void hbDockLayoutRecalcNode(
   HB_DOCK_LAYOUT_NODE * pNode,
   const RECT * pRect )
{
   RECT rcFirst;
   RECT rcSecond;

   LONG Size;
   LONG Split;

   if( pNode == NULL )
      return;

   pNode->Rect = *pRect;

   if( pNode->Type == HB_LAYOUT_LEAF )
   {
      if( pNode->pContainer != NULL )
      {
         pNode->pContainer->Rect = *pRect;

         hbDockLayoutApplyContainer(
            pNode->pContainer );
      }

      return;
   }

   rcFirst = *pRect;
   rcSecond = *pRect;

   if( pNode->Type == HB_LAYOUT_HORIZONTAL )
   {
      Size =
         pRect->right -
         pRect->left;

      Split =
         ( LONG ) ( ( double ) Size *
                    pNode->Ratio );

      rcFirst.right =
         rcFirst.left +
         Split;

      rcSecond.left =
         rcFirst.right +
         HBDOCK_SPLITTER_SIZE;
   }
   else
   {
      Size =
         pRect->bottom -
         pRect->top;

      Split =
         ( LONG ) ( ( double ) Size *
                    pNode->Ratio );

      rcFirst.bottom =
         rcFirst.top +
         Split;

      rcSecond.top =
         rcFirst.bottom +
         HBDOCK_SPLITTER_SIZE;
   }

   hbDockLayoutRecalcNode(
      pNode->First,
      &rcFirst );

   hbDockLayoutRecalcNode(
      pNode->Second,
      &rcSecond );
}

void hbDockLayoutRecalc(
   HB_DOCK_LAYOUT_TREE * pTree,
   const RECT * pRect )
{
   if( pTree == NULL )
      return;

   if( pTree->Root == NULL )
      return;

   if( pRect == NULL )
      return;

   hbDockLayoutRecalcNode(
      pTree->Root,
      pRect );
}