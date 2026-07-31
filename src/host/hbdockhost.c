#include <windows.h>
#include <windowsx.h>

#include "hbdockhost.h"
#include "hbdocklayout.h"
#include "hbdockhittest.h"
#include "hbdocktreesplitfind.h"
#include "hbdockcaption.h"
#include "hbdockmouse.h"
#include "hbdockmanagerdrag.h"
#include "hbdockmanagerautohide.h"
#include "hbdockmanagerlayout.h"
#include "hbdockmanagermousemove.h"
#include "hbdockcontainer.h"
#include "hbdockautohideanimationmanagertick.h"
#include "hbdocktabgroup.h"
#include "hbdocktabstrip.h"
#include "hbdockmanagerclosetab.h"
#include "hbdockpaneldock.h"
#include "hbdockarray.h"
#include "hbdocktheme.h"
#include "hbdockgradientfill.h"

#define HBDOCK_DRAG_THRESHOLD_CX   4
#define HBDOCK_DRAG_THRESHOLD_CY   4

/* Encuentra, si lo hay, el nodo hoja bajo pt cuyo caption
 * (franja superior del panel) contiene el punto. */
static HB_DOCK_LAYOUT_NODE * hbDockHostFindCaptionAt(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   HB_DOCK_HITTEST Hit;
   RECT rc;

   hbDockHitTestTree(
      pManager->LayoutTree.Root,
      pt,
      &Hit );

   if( Hit.Hit != HB_DOCK_HIT_PANEL || Hit.pNode == NULL )
		return NULL;

	if( Hit.pNode->pContainer != NULL &&
	    Hit.pNode->pContainer->TabGroup.pPanel != NULL &&
	    Hit.pNode->pContainer->TabGroup.pPanel->NoCaption )
		return NULL;

	rc = Hit.pNode->Rect;
   rc.bottom = rc.top + HBDOCK_CAPTION_HEIGHT;

   if( !PtInRect( &rc, pt ) )
      return NULL;

   return Hit.pNode;
}

static void hbDockHostUpdateAutoHideHover(
   HB_DOCK_HOST * pHost,
   POINT pt )
{
   HB_DOCK_PANEL * pHit;

   pHit = hbDockManagerAutoHideHitTest(
      pHost->pManager,
      pt );

   if( pHit != NULL && pHit != pHost->HoverAutoHide )
   {
      if( pHost->HoverAutoHide != NULL )
         hbDockManagerAutoHideCollapseImmediate(
            pHost->pManager,
            pHost->HoverAutoHide );

      pHost->HoverAutoHide = pHit;

      hbDockManagerAutoHideExpand(
         pHost->pManager,
         pHost->HoverAutoHide );

      SetTimer(
         pHost->hWnd,
         HBDOCK_AUTOHIDE_TIMER_ID,
         HBDOCK_AUTOHIDE_TIMER_MS,
         NULL );

      hbDockHostInvalidate( pHost );
   }
}

static void hbDockHostCheckAutoHideLeave(
   HB_DOCK_HOST * pHost )
{
   POINT pt;
   RECT rc;

   if( pHost->HoverAutoHide == NULL )
      return;

   GetCursorPos( &pt );
   ScreenToClient( pHost->hWnd, &pt );

   /*
    * Etapa 76 (fix): antes esto usaba pHost->HoverAutoHide->Rect (el
    * rect ACTUAL del panel) -- durante la animacion de expansion ese
    * rect es mas CHICO que el final (va creciendo de a poco), y este
    * chequeo corre en un timer INDEPENDIENTE del de la animacion. Si
    * el chequeo corria justo en medio de la animacion, con el mouse
    * ya sobre donde el panel VA a terminar (pero el panel todavia no
    * crecio hasta ahi), concluia erroneamente que el mouse estaba
    * afuera y colapsaba el panel a mitad de camino -- confirmado con
    * captura real (se ve expandirse bien, "se estabiliza" -- en
    * realidad colapsa -- despues, con el mouse quieto). Se usa el
    * tamaño FINAL (VisibleRect) para este chequeo, sin importar en
    * que punto de la animacion este el panel.
    */
   if( !hbDockManagerAutoHideGetVisibleRect(
           pHost->pManager,
           pHost->HoverAutoHide,
           &rc ) )
      rc = pHost->HoverAutoHide->Rect;

   if( !PtInRect( &rc, pt ) &&
       hbDockManagerAutoHideHitTest(
          pHost->pManager, pt ) != pHost->HoverAutoHide )
   {
      hbDockManagerAutoHideCollapse(
         pHost->pManager,
         pHost->HoverAutoHide );

      pHost->HoverAutoHide = NULL;

      KillTimer(
         pHost->hWnd,
         HBDOCK_AUTOHIDE_TIMER_ID );

      hbDockHostInvalidate( pHost );
   }
}

BOOL hbDockHostHandleMessage(
   HB_DOCK_HOST * pHost,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam )
{
   POINT pt;
 
   if( pHost == NULL || pHost->pManager == NULL )
      return FALSE;

   switch( uMsg )
   {
      case WM_LBUTTONDOWN:
      {
		 HB_DOCK_LAYOUT_NODE * pSplitNode;
		 HB_DOCK_LAYOUT_NODE * pCaptionNode;
		 
         pt.x = GET_X_LPARAM( lParam );
         pt.y = GET_Y_LPARAM( lParam );

		 pSplitNode = hbDockTreeFindSplitterAt(
		   pHost->pManager->LayoutTree.Root,
		   pt );
         if( pSplitNode != NULL )
         {
            hbDockSplitNodeInit(
               &pHost->ActiveSplit,
               pSplitNode );

            hbDockSplitNodeUpdate(
               &pHost->ActiveSplit );

            hbDockSplitterTrackerBegin(
               &pHost->SplitterTracker,
               &pHost->ActiveSplit,
               pt );

            SetCapture( pHost->hWnd );

            return TRUE;
         }

         pCaptionNode = hbDockHostFindCaptionAt(
            pHost->pManager,
            pt );

		if( pCaptionNode != NULL &&
			pCaptionNode->pContainer != NULL &&
			pCaptionNode->pContainer->TabGroup.pPanel != NULL )
		{
		   RECT rcCaption;

		   rcCaption = pCaptionNode->Rect;
		   rcCaption.bottom = rcCaption.top + HBDOCK_CAPTION_HEIGHT;

		   if( pCaptionNode->pContainer->TabGroup.Count > 1 )
		   {
		      int TabIndex;
		      BOOL bOnClose;

		      TabIndex =
		         hbDockTabStripHitTest(
		            &pCaptionNode->pContainer->TabGroup,
		            &rcCaption,
		            pt,
		            &bOnClose );

		      if( TabIndex >= 0 && bOnClose )
		      {
		         /*
		          * Cerrar ESE tab puntual -- sin iniciar ningun drag.
		          */
		         hbDockManagerCloseTab(
		            pHost->pManager,
		            pCaptionNode->pContainer->TabGroup.Tabs[ TabIndex ].pPanel );

		         hbDockHostInvalidate( pHost );

		         return TRUE;
		      }

		      if( TabIndex >= 0 &&
		          ( UINT ) TabIndex != pCaptionNode->pContainer->TabGroup.ActiveIndex )
		      {
		         /*
		          * Cambiar de pestaña (no era la activa, y no se
		          * clickeo su "x") -- tampoco inicia drag, solo cambia
		          * cual esta activa y recalcula.
		          */
		         hbDockTabGroupSetActive(
		            &pCaptionNode->pContainer->TabGroup,
		            ( UINT ) TabIndex );

		         hbDockManagerLayout(
		            pHost->pManager );

		         hbDockHostInvalidate( pHost );

		         return TRUE;
		      }
		   }
		   else
		   {
		      /*
		       * Etapa 52: caption SIMPLE (un solo panel, sin tira de
		       * pestañas) -- se usa el MISMO calculo de rect que
		       * hbDockCaptionDraw (HB_DOCK_CAPTION Init+Layout) para
		       * el hit-test de la "x"/el pin, en vez del calculo de la
		       * tira de pestañas (que daba un rect LIGERAMENTE
		       * distinto al dibujado real -- confirmado que ni la "x"
		       * ni el pin respondian de forma confiable). Ademas se
		       * agrega el hit-test del PIN (autohide), que antes no
		       * existia en absoluto.
		       */
		      HB_DOCK_CAPTION Caption;
		      HB_DOCK_PANEL * pSinglePanel;

		      pSinglePanel =
		         pCaptionNode->pContainer->TabGroup.pPanel;

		      hbDockCaptionInit(
		         &Caption,
		         pSinglePanel );

		      hbDockCaptionLayout(
		         &Caption,
		         &rcCaption );

		      if( PtInRect( &Caption.CloseRect, pt ) )
		      {
		         hbDockManagerCloseTab(
		            pHost->pManager,
		            pSinglePanel );

		         hbDockHostInvalidate( pHost );

		         return TRUE;
		      }

		      if( PtInRect( &Caption.PinRect, pt ) )
		      {
		         hbDockManagerAutoHidePanel(
		            pHost->pManager,
		            pSinglePanel );

		         hbDockHostInvalidate( pHost );

		         return TRUE;
		      }
		   }

		   /*
		    * Ningun boton especifico -- comportamiento de siempre:
		    * preparar un posible drag.
		    */
		   pHost->PendingDragPanel =
			  pCaptionNode->pContainer->TabGroup.pPanel;

		   pHost->PendingDragPoint = pt;

		   SetCapture(
			  pHost->hWnd );

		   return TRUE;
		}
		
         return FALSE;
      }

      case WM_MOUSEMOVE:

         pt.x = GET_X_LPARAM( lParam );
         pt.y = GET_Y_LPARAM( lParam );

         if( pHost->SplitterTracker.Tracking )
         {
            /*
             * Etapa 48: mantener el cursor de resize durante todo el
             * arrastre, no solo al pasar por encima -- si no, el
             * cursor volveria a flecha normal apenas el mouse se
             * mueve un poco durante el drag (comun si el drag se
             * hace rapido y el puntero se corre ligeramente del
             * splitter en si).
             */
            SetCursor(
               LoadCursor(
                  NULL,
                  pHost->ActiveSplit.Node != NULL &&
                  pHost->ActiveSplit.Node->Type == HB_LAYOUT_HORIZONTAL ?
                     IDC_SIZEWE :
                     IDC_SIZENS ) );

            hbDockSplitterTrackerMove(
               &pHost->SplitterTracker,
               pt );

            hbDockManagerLayout(
               pHost->pManager );

            hbDockHostInvalidate( pHost );

            return TRUE;
         }

         if( pHost->Dragging )
         {
            hbDockManagerDragMove(
               pHost->pManager,
               pt );

            hbDockHostInvalidate( pHost );

            return TRUE;
         }

         if( pHost->PendingDragPanel != NULL )
         {
            if( hbDockMouseMoved(
                   pHost->PendingDragPoint,
                   pt,
                   HBDOCK_DRAG_THRESHOLD_CX,
                   HBDOCK_DRAG_THRESHOLD_CY ) )
            {
               hbDockManagerBeginDrag(
                  pHost->pManager,
                  pHost->PendingDragPanel,
                  pHost->PendingDragPoint );

               pHost->PendingDragPanel = NULL;
               pHost->Dragging = 1;

               hbDockManagerDragMove(
                  pHost->pManager,
                  pt );

               hbDockHostInvalidate( pHost );
            }

            return TRUE;
         }

         /*
          * Etapa 48: cursor de resize al pasar el mouse por encima de
          * un splitter, sin necesidad de clickear -- pedido explicito.
          * Se chequea ANTES del hover de autohide (que tiene su propio
          * cursor -- ver hbDockAutoHideSetCursor -- para no pisarlo).
          */
         {
            HB_DOCK_LAYOUT_NODE * pHoverSplit;

            pHoverSplit =
               hbDockTreeFindSplitterAt(
                  pHost->pManager->LayoutTree.Root,
                  pt );

            if( pHoverSplit != NULL )
            {
               SetCursor(
                  LoadCursor(
                     NULL,
                     pHoverSplit->Type == HB_LAYOUT_HORIZONTAL ?
                        IDC_SIZEWE :
                        IDC_SIZENS ) );

               return TRUE;
            }
         }

         hbDockHostUpdateAutoHideHover(
            pHost,
            pt );

         return FALSE;

      case WM_LBUTTONUP:

         pt.x = GET_X_LPARAM( lParam );
         pt.y = GET_Y_LPARAM( lParam );

         if( pHost->SplitterTracker.Tracking )
         {
            hbDockSplitterTrackerEnd(
               &pHost->SplitterTracker );

            ReleaseCapture();

            return TRUE;
         }

         if( pHost->Dragging )
         {
            hbDockManagerEndDrag(
               pHost->pManager,
               pt );

            pHost->Dragging = 0;

            ReleaseCapture();

            hbDockHostInvalidate( pHost );

            return TRUE;
         }

         if( pHost->PendingDragPanel != NULL )
         {
            /* Fue un click simple, sin arrastre: solo
             * activa el panel bajo el caption. */
            pHost->PendingDragPanel = NULL;

            ReleaseCapture();

            return TRUE;
         }

         return FALSE;

      case WM_CAPTURECHANGED:

         /* Otro control se robo la captura del mouse:
          * cancela cualquier operacion en curso en vez
          * de dejarla en un estado inconsistente. */
         if( pHost->Dragging )
         {
            hbDockManagerCancelDrag(
               pHost->pManager );

            pHost->Dragging = 0;
         }

         if( pHost->SplitterTracker.Tracking )
            hbDockSplitterTrackerEnd(
               &pHost->SplitterTracker );

         pHost->PendingDragPanel = NULL;

         return FALSE;

      case WM_TIMER:

         if( wParam == HBDOCK_AUTOHIDE_TIMER_ID )
         {
            hbDockHostCheckAutoHideLeave(
               pHost );

            /*
             * Etapa 79: con el overlay popup real, el contenido ya
             * no es hijo directo de la ventana principal mientras
             * esta expandido (esta reparentado adentro de la popup)
             * -- no hace falta tocar pAH->Panel->hWnd aca. Se
             * refuerza solo la popup misma (HWND_TOP alcanza; las
             * popup mantienen su z-order de forma nativa y confiable,
             * a diferencia de una ventana hija).
             */
            if( pHost->pManager != NULL &&
                pHost->pManager->AutoHideManager.hExpandCaptionWnd != NULL &&
                IsWindowVisible( pHost->pManager->AutoHideManager.hExpandCaptionWnd ) )
            {
               SetWindowPos(
                  pHost->pManager->AutoHideManager.hExpandCaptionWnd,
                  HWND_TOP,
                  0, 0, 0, 0,
                  SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE );
            }

            return TRUE;
         }

         /* Etapa 11: tick real del motor de animacion de AutoHide.
          * Sin esto, el motor de slide (Etapa 5) nunca avanzaba --
          * quedaba todo escrito pero sin nadie llamandolo. */
         if( wParam == HBDOCK_ANIMATION_TIMER_ID )
         {
            if( pHost->pManager != NULL )
            {
               hbDockAutoHideAnimationManagerTick(
                  &pHost->pManager->AnimationManager,
                  pHost->pManager );
            }

            return TRUE;
         }

         return FALSE;
   }

   return FALSE;
}

/*
 * Nota de estabilizacion (Etapa 28): recorre el arbol y fuerza que
 * cada ventana de caption REAL (Etapa 24, pContainer->hWnd) se
 * muestre y repinte -- sin tocar geometria (nada de GetClientRect),
 * sin RDW_ALLCHILDREN, sin acercarse a ninguna ventana fuera del
 * arbol de HBDock32 (como la toolbar de FiveWin). Reemplaza la
 * version vieja (Etapa 18, pintado manual via GetDC -- innecesaria
 * desde que los captions son ventanas propias que se pintan solas).
 *
 * Motivo: HBDockRefreshLayout (que si toca GetClientRect y
 * recalcula todo el arbol) resulto insuficiente para que los
 * captions aparecieran en el primer frame -- esta funcion es un
 * fallback mas directo y mucho mas acotado: si la ventana ya existe
 * y esta bien posicionada (lo que hbDockLayoutApplyContainer ya
 * garantiza), alcanza con pedirle a Windows que la muestre y
 * repinte, sin volver a calcular nada.
 */
static void hbDockHostPaintCaptionsNode(
   HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return;

   if( pNode->Type == HB_LAYOUT_LEAF )
   {
      HB_DOCK_CONTAINER * pContainer;

      pContainer = pNode->pContainer;

      if( pContainer == NULL || pContainer->hWnd == NULL )
         return;

      ShowWindow(
         pContainer->hWnd,
         SW_SHOWNA );

      InvalidateRect(
         pContainer->hWnd,
         NULL,
         TRUE );

      UpdateWindow(
         pContainer->hWnd );

      return;
   }

   hbDockHostPaintCaptionsNode(
      pNode->First );

   hbDockHostPaintCaptionsNode(
      pNode->Second );
}

void hbDockHostPaintCaptions(
   HB_DOCK_HOST * pHost )
{
   if( pHost == NULL )
      return;

   if( pHost->pManager == NULL )
      return;

   hbDockHostPaintCaptionsNode(
      pHost->pManager->LayoutTree.Root );
}

/*
 * Etapa 48: ver nota en hbdockhost.h.
 */
static void hbDockHostPaintSplittersNode(
   HB_DOCK_LAYOUT_NODE * pNode,
   HDC hDC )
{
   RECT rc;

   if( pNode == NULL )
      return;

   if( pNode->Type == HB_LAYOUT_LEAF )
      return;

   hbDockNodeSplitterRect(
      pNode,
      &rc );

   /*
    * EDGE_RAISED (highlight arriba/izq, sombra abajo/der) es el
    * bisel clasico de un "grip" o separador 3D de Windows -- BF_RECT
    * lo aplica en los 4 lados del rect.
    */
   DrawEdge(
      hDC,
      &rc,
      EDGE_RAISED,
      BF_RECT );

   hbDockHostPaintSplittersNode(
      pNode->First,
      hDC );

   hbDockHostPaintSplittersNode(
      pNode->Second,
      hDC );
}

void hbDockHostPaintSplitters(
   HB_DOCK_HOST * pHost,
   HDC hDC )
{
   if( pHost == NULL || hDC == NULL )
      return;

   if( pHost->pManager == NULL )
      return;

   hbDockHostPaintSplittersNode(
      pHost->pManager->LayoutTree.Root,
      hDC );
}

/*
 * Etapa 53: ver nota en hbdockhost.h.
 */
void hbDockHostPaintAutoHideTabs(
   HB_DOCK_HOST * pHost,
   HDC hDC )
{
   int i;

   if( pHost == NULL || hDC == NULL )
      return;

   if( pHost->pManager == NULL )
      return;

   for( i = 0; i < pHost->pManager->AutoHideManager.Panes.Count; i++ )
   {
      HB_DOCK_AUTOHIDE * pAH;
      HB_DOCK_SITE Site;
      BOOL bVertical;
      LOGFONT lf;
      HFONT hFont;
      HFONT hOldFont;
      COLORREF OldTextColor;
      int OldBkMode;
      int nLen;
      SIZE TextSize;
      HRGN hClipRgn;
      int nSavedDC;

      pAH =
         ( HB_DOCK_AUTOHIDE * )
         hbDockArrayGet(
            &pHost->pManager->AutoHideManager.Panes,
            i );

      if( pAH == NULL || pAH->Panel == NULL )
         continue;

      Site =
         hbDockPanelGetDockSite(
            pAH->Panel );

      bVertical =
         ( Site == HB_DOCKSITE_LEFT ||
           Site == HB_DOCKSITE_RIGHT );

      /*
       * Etapa 54 (fix): recortar el dibujado a este HiddenRect en
       * particular -- confirmado con captura real que sin esto, el
       * texto rotado (con varias pestañas apiladas, cada una en un
       * segmento de solo 100px de alto) se salia de su propio
       * segmento y pisaba visualmente al de al lado, dando la
       * impresion de que las pestañas estaban superpuestas. Se
       * guarda el estado del DC (SaveDC) para poder restaurar el
       * clip original despues de esta pestaña puntual, sin afectar
       * el resto del pintado.
       */
      nSavedDC =
         SaveDC( hDC );

      hClipRgn =
         CreateRectRgn(
            pAH->HiddenRect.left,
            pAH->HiddenRect.top,
            pAH->HiddenRect.right,
            pAH->HiddenRect.bottom );

      SelectClipRgn(
         hDC,
         hClipRgn );

      DeleteObject(
         hClipRgn );

      hbDockGradientFillMulti(
         hDC,
         &pAH->HiddenRect,
         &hbDockThemeGetCurrent()->TabInactiveGrad );

      /*
       * Etapa 56: separador entre pestañas apiladas -- una linea
       * clara en el borde superior de cada segmento, para que se
       * distingan visualmente unas de otras (pedido explicito).
       */
      {
         HPEN hSepPen;
         HPEN hOldSepPen;

         hSepPen =
            CreatePen(
               PS_SOLID,
               1,
               hbDockThemeGetCurrent()->TabSeparator );

         hOldSepPen =
            ( HPEN ) SelectObject(
               hDC,
               hSepPen );

         MoveToEx(
            hDC,
            pAH->HiddenRect.left,
            pAH->HiddenRect.top,
            NULL );

         LineTo(
            hDC,
            pAH->HiddenRect.right,
            pAH->HiddenRect.top );

         SelectObject(
            hDC,
            hOldSepPen );

         DeleteObject(
            hSepPen );
      }

      ZeroMemory(
         &lf,
         sizeof( lf ) );

      lf.lfHeight = -13;
      lf.lfWeight = FW_NORMAL;

      /*
       * Etapa 56: ANTIALIASED_QUALITY en vez del default -- ClearType
       * (el default de Windows moderno) asume texto horizontal
       * (subpixel RGB) y suele verse notablemente peor/mas ilegible
       * en texto ROTADO; antialiasing en escala de grises se ve mas
       * limpio para este caso. OUT_TT_PRECIS para preferir una
       * fuente TrueType real (rota mejor que una bitmap).
       */
      lf.lfQuality = ANTIALIASED_QUALITY;
      lf.lfOutPrecision = OUT_TT_PRECIS;

      /*
       * Escapement/Orientation en decimas de grado -- 900 = 90
       * grados, texto leible de abajo hacia arriba. Solo aplica en
       * los lados LEFT/RIGHT (franja vertical angosta); en
       * TOP/BOTTOM el texto va horizontal normal.
       */
      lf.lfEscapement  = bVertical ? 900 : 0;
      lf.lfOrientation = bVertical ? 900 : 0;

      lstrcpy(
         lf.lfFaceName,
         TEXT( "MS Shell Dlg" ) );

      hFont =
         CreateFontIndirect(
            &lf );

      hOldFont =
         ( HFONT ) SelectObject(
            hDC,
            hFont );

      OldTextColor =
         SetTextColor(
            hDC,
            hbDockThemeGetCurrent()->TabInactiveText );

      OldBkMode =
         SetBkMode(
            hDC,
            TRANSPARENT );

      nLen =
         lstrlen(
            pAH->Panel->Caption );

      if( bVertical )
      {
         int nX;
         int nY;

         GetTextExtentPoint32(
            hDC,
            pAH->Panel->Caption,
            nLen,
            &TextSize );

         /*
          * Etapa 57 (fix): con escapement 900, el CUERPO del glifo
          * (su altura de fuente) se extiende hacia la DERECHA del
          * punto de anclaje X, no hacia la izquierda -- con el
          * anclaje anterior (centro + 5, cerca ya del borde derecho
          * de una franja de solo ~24px) el cuerpo del texto quedaba
          * mayormente FUERA de la franja, y el clip (Etapa 54) lo
          * recortaba por completo -- invisible. Ahora se ancla cerca
          * del borde IZQUIERDO, dejando que el cuerpo se extienda
          * hacia adentro de la franja angosta.
          */
         nX =
            pAH->HiddenRect.left + 3;

         /*
          * Etapa 56 (fix): antes esto centraba con una formula que,
          * si el texto era mas largo que el segmento (TextSize.cx >
          * alto del segmento), empujaba el ANCLAJE mas alla del
          * borde inferior, quedando la mayor parte (o todo) el texto
          * arriba del propio clip -- practicamente invisible.
          * Ahora se ancla simplemente cerca del borde INFERIOR del
          * segmento (con un margen chico) -- el texto sube desde
          * ahi, garantizando que el INICIO del nombre siempre se vea;
          * si un nombre es mas largo que el segmento, se corta
          * prolijo por el clip en la parte de ARRIBA (el final del
          * nombre), nunca el principio.
          */
         nY =
            pAH->HiddenRect.bottom - 8;

         TextOut(
            hDC,
            nX,
            nY,
            pAH->Panel->Caption,
            nLen );
      }
      else
      {
         RECT rcText;

         rcText = pAH->HiddenRect;

         DrawText(
            hDC,
            pAH->Panel->Caption,
            nLen,
            &rcText,
            DT_CENTER |
            DT_VCENTER |
            DT_SINGLELINE |
            DT_END_ELLIPSIS );
      }

      SetBkMode(
         hDC,
         OldBkMode );

      SetTextColor(
         hDC,
         OldTextColor );

      SelectObject(
         hDC,
         hOldFont );

      DeleteObject(
         hFont );

      RestoreDC(
         hDC,
         nSavedDC );
   }
}
