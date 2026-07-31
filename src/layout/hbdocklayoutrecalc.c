#include <windows.h>

#include "hbdocklayoutrecalc.h"
#include "hbdocklayouttree.h"
#include "hbdockcontainer.h"
#include "hbdockcaption.h"
#include "hbdockcaptionwindow.h"
#include "hbdockconfig.h"
#include "hbdockmanager.h"
#include "hbdockmanagerautohide.h"
#include "hbdockpaneldock.h"
#include "hbdockarray.h"

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
   HB_DOCK_CONTAINER * pContainer,
   void * pManagerVoid )
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

   /*
    * Etapa 64: pedido explicito -- si el panel activo pide
    * NoCaption, no se reserva HBDOCK_CAPTION_HEIGHT (el panel ocupa
    * el contenedor COMPLETO, sin la franja de caption arriba) y la
    * ventana de caption se OCULTA en vez de actualizarse/mostrarse
    * -- pensado para usar un panel como area central de trabajo
    * (tipo MDI), sin barra de titulo ni botones de pin/cerrar.
    */
   if( !pPanel->NoCaption )
   {
      rc.top += HBDOCK_CAPTION_HEIGHT;

      if( rc.top > rc.bottom )
         rc.top = rc.bottom;
   }

   /*
    * Etapa 24: la franja de caption ahora es una ventana hija propia
    * (ver hbdockcaptionwindow.c) en vez de pintarse "por encima"
    * desde la ventana principal via GetDC -- eso quedaba
    * intermitentemente recortado por el clipping automatico de
    * ventanas hijas de GetDC. Se reposiciona con el rect EXACTO de
    * la franja (desde pContainer->Rect.top, sin el offset de
    * HBDOCK_CAPTION_HEIGHT que ya se le sumo a "rc" para el panel).
    */
   if( pContainer->hWnd != NULL )
   {
      if( pPanel->NoCaption )
      {
         ShowWindow(
            pContainer->hWnd,
            SW_HIDE );
      }
      else
      {
         RECT rcCaption;

         rcCaption = pContainer->Rect;
         rcCaption.bottom = rcCaption.top + HBDOCK_CAPTION_HEIGHT;

         if( rcCaption.bottom > pContainer->Rect.bottom )
            rcCaption.bottom = pContainer->Rect.bottom;

         /*
          * Etapa 72: pedido explicito -- cuando un panel de AutoHide
          * esta expandido, su propio caption (ver
          * hbDockAutoHideExpandCaptionShow) se dibuja ENCIMA de la
          * franja izquierda/derecha del caption de este contenedor
          * -- ambos son correctos en su propio ancho, pero al ser
          * dos barras azules identicas y contiguas se leian como
          * una sola con "dos pares de o/x". Se achica el rect de
          * ESTE caption para dejarle el lugar al del panel
          * expandido, en vez de superponerse -- una sola barra
          * prolija en vez de dos.
          */
         if( pManagerVoid != NULL )
         {
            HB_DOCK_MANAGER * pManager = ( HB_DOCK_MANAGER * ) pManagerVoid;
            int i;

            for( i = 0; i < pManager->AutoHideManager.Panes.Count; i++ )
            {
               HB_DOCK_AUTOHIDE * pAH =
                  ( HB_DOCK_AUTOHIDE * )
                  hbDockArrayGet(
                     &pManager->AutoHideManager.Panes,
                     i );

               HB_DOCK_SITE Site;

               if( pAH == NULL ||
                   !pAH->Expanded ||
                   pAH->Panel == NULL )
                  continue;

               Site =
                  hbDockPanelGetDockSite( pAH->Panel );

               if( Site == HB_DOCKSITE_LEFT &&
                   pAH->Panel->Rect.right > rcCaption.left )
                  rcCaption.left = pAH->Panel->Rect.right;

               if( Site == HB_DOCKSITE_RIGHT &&
                   pAH->Panel->Rect.left < rcCaption.right )
                  rcCaption.right = pAH->Panel->Rect.left;
            }

            if( rcCaption.left > rcCaption.right )
               rcCaption.left = rcCaption.right;
         }

         hbDockCaptionWindowUpdate(
            pContainer->hWnd,
            &rcCaption,
            pContainer );
      }
   }

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
   const RECT * pRect,
   void * pManagerVoid )
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
            pNode->pContainer,
            pManagerVoid );
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

      /*
       * Etapa 63: pedido explicito -- "ancho fijo de verdad" (no
       * solo al acoplar, Etapa 49, sino en CADA resize posterior).
       * Si uno de los dos hijos directos es una hoja con
       * DockSize.cx fijado (ver hbDockPanelSetDockSize), se
       * recalcula el Ratio necesario para que ESE panel mantenga
       * exactamente esa cantidad de pixeles en el espacio
       * ACTUALMENTE disponible -- el otro lado (el hermano, sea una
       * hoja simple o todo un subarbol) absorbe el resto del
       * cambio de tamaño de la ventana. Si DockSize no esta
       * fijado (0, el default), el comportamiento no cambia --
       * sigue siendo el Ratio proporcional de siempre.
       */
      if( Size > 0 &&
          pNode->First != NULL &&
          pNode->First->Type == HB_LAYOUT_LEAF &&
          pNode->First->pContainer != NULL &&
          pNode->First->pContainer->TabGroup.pPanel != NULL &&
          pNode->First->pContainer->TabGroup.pPanel->DockSize.cx > 0 )
      {
         pNode->Ratio =
            ( float ) pNode->First->pContainer->TabGroup.pPanel->DockSize.cx /
            ( float ) Size;
      }
      else if( Size > 0 &&
               pNode->Second != NULL &&
               pNode->Second->Type == HB_LAYOUT_LEAF &&
               pNode->Second->pContainer != NULL &&
               pNode->Second->pContainer->TabGroup.pPanel != NULL &&
               pNode->Second->pContainer->TabGroup.pPanel->DockSize.cx > 0 )
      {
         pNode->Ratio =
            1.0f -
            ( ( float ) pNode->Second->pContainer->TabGroup.pPanel->DockSize.cx /
              ( float ) Size );
      }

      if( pNode->Ratio < 0.05f )
         pNode->Ratio = 0.05f;

      if( pNode->Ratio > 0.95f )
         pNode->Ratio = 0.95f;

      Split =
         ( LONG ) ( ( double ) Size *
                    pNode->Ratio );

      rcFirst.right =
         rcFirst.left +
         Split;

      rcSecond.left =
         rcFirst.right +
         HBDOCK_SPLITTER_WIDTH;
   }
   else
   {
      Size =
         pRect->bottom -
         pRect->top;

      /* Etapa 63: mismo criterio que arriba, para el eje vertical
       * (TOP/BOTTOM, DockSize.cy). */
      if( Size > 0 &&
          pNode->First != NULL &&
          pNode->First->Type == HB_LAYOUT_LEAF &&
          pNode->First->pContainer != NULL &&
          pNode->First->pContainer->TabGroup.pPanel != NULL &&
          pNode->First->pContainer->TabGroup.pPanel->DockSize.cy > 0 )
      {
         pNode->Ratio =
            ( float ) pNode->First->pContainer->TabGroup.pPanel->DockSize.cy /
            ( float ) Size;
      }
      else if( Size > 0 &&
               pNode->Second != NULL &&
               pNode->Second->Type == HB_LAYOUT_LEAF &&
               pNode->Second->pContainer != NULL &&
               pNode->Second->pContainer->TabGroup.pPanel != NULL &&
               pNode->Second->pContainer->TabGroup.pPanel->DockSize.cy > 0 )
      {
         pNode->Ratio =
            1.0f -
            ( ( float ) pNode->Second->pContainer->TabGroup.pPanel->DockSize.cy /
              ( float ) Size );
      }

      if( pNode->Ratio < 0.05f )
         pNode->Ratio = 0.05f;

      if( pNode->Ratio > 0.95f )
         pNode->Ratio = 0.95f;

      Split =
         ( LONG ) ( ( double ) Size *
                    pNode->Ratio );

      rcFirst.bottom =
         rcFirst.top +
         Split;

      rcSecond.top =
         rcFirst.bottom +
         HBDOCK_SPLITTER_WIDTH;
   }

   hbDockLayoutRecalcNode(
      pNode->First,
      &rcFirst,
      pManagerVoid );

   hbDockLayoutRecalcNode(
      pNode->Second,
      &rcSecond,
      pManagerVoid );
}

void hbDockLayoutRecalc(
   HB_DOCK_LAYOUT_TREE * pTree,
   const RECT * pRect,
   void * pManagerVoid )
{
   if( pTree == NULL )
      return;

   if( pTree->Root == NULL )
      return;

   if( pRect == NULL )
      return;

   hbDockLayoutRecalcNode(
      pTree->Root,
      pRect,
      pManagerVoid );
}