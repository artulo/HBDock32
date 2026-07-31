#include "hbdockmanagerautohide.h"

#include "hbdockmanagerundock.h"
#include "hbdockmanagerlayout.h"
#include "hbdockmanagerrefreshlayout.h"
#include "hbdockmanagerdock.h"

#include "hbdocklayoutinsertpanel.h"

#include "hbdockpaneldock.h"

#include "hbdockarray.h"
#include "hbdockconfig.h"
#include "hbdockautohideslideengine.h"
#include "hbdockautohideanimationadd.h"
#include "hbdockautohideexpandcaption.h"
#include "hbdockcaption.h"

static HB_DOCK_AUTOHIDE * hbDockManagerFindAutoHide(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   int i;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE * pAutoHide =
         ( HB_DOCK_AUTOHIDE * ) hbDockArrayGet(
            &pManager->AutoHideManager.Panes,
            i );

      if( pAutoHide != NULL && pAutoHide->Panel == pPanel )
         return pAutoHide;
   }

   return NULL;
}

/*
 * Etapa 53: pedido explicito -- dos o mas paneles autohidden en el
 * MISMO lado quedaban con el HiddenRect exactamente superpuesto (la
 * funcion de abajo siempre calculaba la misma posicion fija, sin
 * saber cuantos otros ya habia ahi) -- el segundo tapaba
 * completamente al primero, imposible de distinguir o clickear por
 * separado. Se cuenta cuantos paneles YA estan autohidden en el
 * mismo Site (excluyendo al propio pPanel, por si ya estuviera en
 * la lista) para calcular un indice de apilamiento, y se offsetea
 * cada uno HBDOCK_AUTOHIDE_TAB_LENGTH pixeles a lo largo del borde.
 */
#define HBDOCK_AUTOHIDE_TAB_LENGTH   130

static int hbDockManagerCountAutoHideOnSite(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_SITE Site,
   HB_DOCK_PANEL * pExclude )
{
   int i;
   int n;

   n = 0;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE * pAH =
         ( HB_DOCK_AUTOHIDE * )
         hbDockArrayGet(
            &pManager->AutoHideManager.Panes,
            i );

      if( pAH != NULL &&
          pAH->Panel != pExclude &&
          pAH->Panel != NULL &&
          hbDockPanelGetDockSite( pAH->Panel ) == Site )
         n++;
   }

   return n;
}

static void hbDockManagerCalcAutoHideRects(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_SITE Site,
   int nStackIndex,
   RECT * pHidden,
   RECT * pVisible )
{
   RECT rc;
   int cx;
   int cy;
   int nOffset;

   GetClientRect(
      pManager->hMainWnd,
      &rc );

   /* Etapa 37: ver nota en hbdockmanager.h. */
   rc.top += pManager->TopMargin;

   if( rc.top > rc.bottom )
      rc.top = rc.bottom;

   cx = pPanel->DockSize.cx > 0 ?
        pPanel->DockSize.cx :
        pPanel->MinWidth;

   cy = pPanel->DockSize.cy > 0 ?
        pPanel->DockSize.cy :
        pPanel->MinHeight;;

   /*
    * Etapa 62: piso minimo -- sin esto, un DockSize/MinWidth/
    * MinHeight en 0 (por el motivo que sea -- confirmado un caso
    * real: SetDockSize llamado con el parametro equivocado para el
    * sitio, ej. SetDockSize(260) en un panel de TOP le da el 260 al
    * ANCHO, dejando el ALTO en 0) terminaba calculando un
    * VisibleRect de alto/ancho CERO -- el panel "se expandia" sin
    * ocupar ningun espacio visible.
    */
   if( cx < 60 )
      cx = 60;

   if( cy < 60 )
      cy = 60;

   nOffset =
      nStackIndex *
      HBDOCK_AUTOHIDE_TAB_LENGTH;

   switch( Site )
   {
      case HB_DOCKSITE_RIGHT:

         SetRect(
            pHidden,
            rc.right - HBDOCK_AUTOHIDE_STRIP,
            rc.top + nOffset,
            rc.right,
            min( rc.top + nOffset + HBDOCK_AUTOHIDE_TAB_LENGTH, rc.bottom ) );

         /*
          * Etapa 74: pedido explicito -- el panel expandido arranca
          * DESPUES de la franja del tab (no desde el borde de la
          * ventana), para que el tab quede siempre visible/clickeable
          * y no tapado por el propio panel que representa.
          */
         SetRect(
            pVisible,
            rc.right - HBDOCK_AUTOHIDE_STRIP - cx,
            rc.top,
            rc.right - HBDOCK_AUTOHIDE_STRIP,
            rc.bottom );
         break;

      case HB_DOCKSITE_TOP:

         SetRect(
            pHidden,
            rc.left + nOffset,
            rc.top,
            min( rc.left + nOffset + HBDOCK_AUTOHIDE_TAB_LENGTH, rc.right ),
            rc.top + HBDOCK_AUTOHIDE_STRIP );

         SetRect(
            pVisible,
            rc.left,
            rc.top + HBDOCK_AUTOHIDE_STRIP,
            rc.right,
            rc.top + HBDOCK_AUTOHIDE_STRIP + cy );
         break;

      case HB_DOCKSITE_BOTTOM:

         SetRect(
            pHidden,
            rc.left + nOffset,
            rc.bottom - HBDOCK_AUTOHIDE_STRIP,
            min( rc.left + nOffset + HBDOCK_AUTOHIDE_TAB_LENGTH, rc.right ),
            rc.bottom );

         SetRect(
            pVisible,
            rc.left,
            rc.bottom - HBDOCK_AUTOHIDE_STRIP - cy,
            rc.right,
            rc.bottom - HBDOCK_AUTOHIDE_STRIP );
         break;

      case HB_DOCKSITE_LEFT:
      default:

         SetRect(
            pHidden,
            rc.left,
            rc.top + nOffset,
            rc.left + HBDOCK_AUTOHIDE_STRIP,
            min( rc.top + nOffset + HBDOCK_AUTOHIDE_TAB_LENGTH, rc.bottom ) );

         SetRect(
            pVisible,
            rc.left + HBDOCK_AUTOHIDE_STRIP,
            rc.top,
            rc.left + HBDOCK_AUTOHIDE_STRIP + cx,
            rc.bottom );
         break;
   }
}

void hbDockManagerAutoHidePanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;
   HB_DOCK_SITE Site;

   if( pManager == NULL || pPanel == NULL )
      return;

   if( hbDockManagerFindAutoHide( pManager, pPanel ) != NULL )
      return;

   Site = hbDockPanelGetDockSite( pPanel );

   /*
    * Nota de estabilizacion: AutoHide no tiene sentido para un panel
    * sin un borde claro contra el cual replegarse (CENTER -- un
    * panel tabificado -- o NONE). hbDockManagerCalcAutoHideRects
    * solo maneja LEFT/RIGHT/TOP/BOTTOM en su switch; con CENTER o
    * NONE, pHidden/pVisible quedaban con memoria sin inicializar
    * (nunca se les asignaba nada), y eso corrompia el resto del
    * layout -- confirmado con captura real: dejaba toda la ventana
    * en blanco. Se rechaza de forma segura en vez de proceder con
    * rects invalidos.
    */
   if( Site != HB_DOCKSITE_LEFT &&
       Site != HB_DOCKSITE_RIGHT &&
       Site != HB_DOCKSITE_TOP &&
       Site != HB_DOCKSITE_BOTTOM )
      return;

   hbDockManagerUndockPanel(
      pManager,
      pPanel );

   pAutoHide = ( HB_DOCK_AUTOHIDE * ) calloc(
      1,
      sizeof( HB_DOCK_AUTOHIDE ) );

   if( pAutoHide == NULL )
      return;

   hbDockAutoHideInit(
      pAutoHide,
      pPanel );

   hbDockManagerCalcAutoHideRects(
      pManager,
      pPanel,
      Site,
      hbDockManagerCountAutoHideOnSite(
         pManager,
         Site,
         pPanel ),
      &pAutoHide->HiddenRect,
      &pAutoHide->VisibleRect );

   hbDockAutoHideEnable(
      pAutoHide,
      1 );

   hbDockAutoHideCollapse(
      pAutoHide );

   if( pPanel->hWnd != NULL )
   {
      /*
       * Etapa 71: pedido explicito -- artefacto visual confirmado
       * (resto de color del panel autohidden quedando pintado en la
       * zona que dejo vacante -- literalmente el fondo VIEJO del
       * panel sin borrar). Con WS_CLIPCHILDREN (Etapa 69) la
       * ventana principal ya NO pinta por encima de sus hijos por
       * defecto -- si un panel se oculta SIN invalidar
       * explicitamente el rect que ocupaba, esa zona puede quedar
       * con los pixeles viejos hasta que algo mas la toque. Se
       * invalida el ULTIMO rect conocido del panel (coordenadas de
       * la ventana principal) antes de ocultarlo.
       */
      InvalidateRect(
         pManager->hMainWnd,
         &pPanel->Rect,
         TRUE );

      ShowWindow(
         pPanel->hWnd,
         SW_HIDE );
   }

   hbDockArrayAdd(
      &pManager->AutoHideManager.Panes,
      pAutoHide );

   hbDockManagerRefreshLayout(
      pManager );
}

void hbDockManagerAutoHideRestore(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;
   HB_DOCK_SITE Site;
   int i;

   if( pManager == NULL || pPanel == NULL )
      return;

   pAutoHide = hbDockManagerFindAutoHide( pManager, pPanel );

   if( pAutoHide == NULL )
      return;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      if( hbDockArrayGet(
             &pManager->AutoHideManager.Panes,
             i ) == pAutoHide )
      {
         hbDockArrayRemove(
            &pManager->AutoHideManager.Panes,
            i );
         break;
      }
   }
 
   free( pAutoHide );

   Site = hbDockPanelGetDockSite( pPanel );

   pPanel->Visible = 1;

   if( pPanel->hWnd != NULL )
      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );

   /*
    * Nota de estabilizacion: esta funcion reinsertaba usando
    * pPanel->pContainer -- pero hbDockManagerAutoHidePanel llama a
    * hbDockManagerUndockPanel al entrar en autohide, que (correctamente,
    * desde que se asigna el enlace inverso panel-contenedor) deja
    * pPanel->pContainer en NULL. Reinsertar con un contenedor NULL
    * fallaba en silencio. Se delega en hbDockManagerDockPanel, que
    * ya crea un contenedor nuevo, inserta, asigna el enlace inverso
    * y repinta -- el mismo camino que "Dock()" normal.
    */
   hbDockManagerDockPanel(
      pManager,
      pPanel,
      ( HB_DOCK_GUIDE_TYPE ) Site );
}

void hbDockManagerAutoHideExpand(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;
   RECT rcStart;
   RECT rcScreen;

   if( pManager == NULL || pPanel == NULL )
      return;

   pAutoHide = hbDockManagerFindAutoHide( pManager, pPanel );

   if( pAutoHide == NULL || pAutoHide->Expanded )
      return;

   pAutoHide->Expanded = 1;

   /*
    * Etapa 79: rediseno -- en vez de mover pPanel->hWnd directo
    * (compitiendo por z-order contra sus hermanos acoplados), se
    * muestra/reparenta el overlay popup (ver
    * hbdockautohideexpandcaption.c) YA ACA, al EMPEZAR a expandir --
    * con el rect INICIAL (HiddenRect si va a animarse, VisibleRect
    * si es el salto instantaneo). Los ticks de la animacion
    * (hbDockAutoHideApplySlide) despues solo REPOSICIONAN ese mismo
    * overlay ya reparentado, sin volver a tocar el z-order.
    */
   rcStart =
      pAutoHide->Animation ?
         pAutoHide->HiddenRect :
         pAutoHide->VisibleRect;

   pAutoHide->Panel->Rect = rcStart;

   rcScreen = rcStart;

   MapWindowPoints(
      pManager->hMainWnd,
      NULL,
      ( POINT * ) &rcScreen,
      2 );

   hbDockAutoHideExpandCaptionShow(
      pManager,
      pPanel,
      &rcScreen );

   /* Etapa 11: si el panel tiene animacion habilitada, no saltamos
    * directo a VisibleRect -- arrancamos el deslizamiento y lo
    * registramos en el AnimationManager del manager; el timer real
    * (Etapa 11, hbdockhost.c) lo va llevando de a poco en cada tick.
    * Si Animation esta apagado para este panel, se mantiene el salto
    * instantaneo de siempre (hbDockAutoHideExpand, Etapa 1). */
   if( pAutoHide->Animation )
   {
      pAutoHide->SlideSize = 100;
      pAutoHide->SlidePosition = 0;
      pAutoHide->SlideStep = 20;

      hbDockAutoHideSlideIn(
         pAutoHide );

      hbDockAutoHideAnimationAddPane(
         &pManager->AnimationManager,
         pAutoHide );
   }
   else
   {
      hbDockAutoHideExpand( pAutoHide );

      /*
       * Etapa 79: salto instantaneo -- llamar Show de nuevo con el
       * rect FINAL (VisibleRect), ahora que ya esta reparentado, para
       * que quede posicionado ahi directamente (sin animacion).
       */
      rcScreen = pAutoHide->VisibleRect;

      MapWindowPoints(
         pManager->hMainWnd,
         NULL,
         ( POINT * ) &rcScreen,
         2 );

      hbDockAutoHideExpandCaptionShow(
         pManager,
         pPanel,
         &rcScreen );
   }
}

void hbDockManagerAutoHideCollapse(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;

   if( pManager == NULL || pPanel == NULL )
      return;

   pAutoHide = hbDockManagerFindAutoHide( pManager, pPanel );

   if( pAutoHide == NULL || !pAutoHide->Expanded )
      return;

   pAutoHide->Expanded = 0;

   if( pAutoHide->Animation )
   {
      /* Etapa 11: al contrario que Expand, aca NO ocultamos la
       * ventana todavia -- tiene que verse deslizarse hacia afuera.
       * hbDockAutoHideAnimationManagerTick la oculta (SW_HIDE) recien
       * cuando el deslizamiento termina de verdad. */
      pAutoHide->SlideSize = 100;

      if( pAutoHide->SlidePosition <= 0 )
         pAutoHide->SlidePosition = 100;

      pAutoHide->SlideStep = 20;

      hbDockAutoHideSlideOut(
         pAutoHide );

      hbDockAutoHideAnimationAddPane(
         &pManager->AnimationManager,
         pAutoHide );
   }
   else
   {
      hbDockAutoHideCollapse( pAutoHide );

      /* Etapa 79: hbDockAutoHideExpandCaptionHide ya oculta y
       * reparenta pPanel->hWnd de vuelta a la ventana principal --
       * no hace falta tocarlo aca aparte. */
      hbDockAutoHideExpandCaptionHide(
         pManager );
   }
}

/*
 * Etapa 70: pedido explicito -- al pasar el mouse de una pestaña de
 * AutoHide DIRECTO a otra (sin que la primera llegue a colapsar del
 * todo), hbDockHostUpdateAutoHideHover llamaba al Collapse NORMAL
 * (animado, si Animation esta prendido -- el default) para la
 * anterior, mientras la nueva arrancaba su propio Expand (tambien
 * animado) -- durante los pocos frames que dura la transicion, AMBAS
 * quedaban parcialmente visibles a la vez, y como los paneles del
 * mismo lado (ej. dos LEFT) arrancan su VisibleRect desde el MISMO
 * borde (x=0), se veian superpuestas/mezcladas -- confirmado con
 * captura real. Esta version salta directo al colapso instantaneo
 * (sin animar), sin importar la configuracion de Animation de ESE
 * panel -- pensada especificamente para el momento de cambiar de
 * pestaña, no para un colapso "normal" (que si debe poder animarse).
 */
void hbDockManagerAutoHideCollapseImmediate(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;

   if( pManager == NULL || pPanel == NULL )
      return;

   pAutoHide = hbDockManagerFindAutoHide( pManager, pPanel );

   if( pAutoHide == NULL || !pAutoHide->Expanded )
      return;

   pAutoHide->Expanded = 0;

   hbDockAutoHideStopSlide(
      pAutoHide );

   hbDockAutoHideCollapse(
      pAutoHide );

   /* Etapa 79: hbDockAutoHideExpandCaptionHide ya oculta y reparenta
    * pPanel->hWnd de vuelta a la ventana principal. */
   hbDockAutoHideExpandCaptionHide(
      pManager );
}

/*
 * Etapa 65: pedido explicito -- la tira de pestañas de AutoHide se
 * pinta directo sobre la ventana principal (no es una ventana real
 * con su propio espacio protegido -- ver hbDockHostPaintAutoHideTabs
 * en hbdockhost.c), y hasta ahora nada le reservaba margen a los
 * paneles ACOPLADOS. Confirmado con caso real: al autohide-ar
 * "Explorador", el arbol se recalcula sin el, y "Archivos" (que
 * pasa a ocupar el borde izquierdo) es una ventana real que
 * TAPA la pestaña pintada ahi -- inaccesible, sin forma de volver a
 * mostrar el panel. Recorre los paneles autohidden y devuelve
 * cuanto margen reservar en cada lado (HBDOCK_AUTOHIDE_STRIP si hay
 * AL MENOS uno en ese lado, 0 si no hay ninguno).
 */
void hbDockManagerGetAutoHideMargins(
   HB_DOCK_MANAGER * pManager,
   int * pLeft,
   int * pTop,
   int * pRight,
   int * pBottom )
{
   int i;
   BOOL bLeft, bTop, bRight, bBottom;

   bLeft = bTop = bRight = bBottom = FALSE;

   if( pLeft != NULL )   *pLeft = 0;
   if( pTop != NULL )    *pTop = 0;
   if( pRight != NULL )  *pRight = 0;
   if( pBottom != NULL ) *pBottom = 0;

   if( pManager == NULL )
      return;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE * pAH =
         ( HB_DOCK_AUTOHIDE * ) hbDockArrayGet(
            &pManager->AutoHideManager.Panes,
            i );

      HB_DOCK_SITE Site;

      if( pAH == NULL || pAH->Panel == NULL )
         continue;

      Site = hbDockPanelGetDockSite( pAH->Panel );

      switch( Site )
      {
         case HB_DOCKSITE_LEFT:   bLeft   = TRUE; break;
         case HB_DOCKSITE_RIGHT:  bRight  = TRUE; break;
         case HB_DOCKSITE_TOP:    bTop    = TRUE; break;
         case HB_DOCKSITE_BOTTOM: bBottom = TRUE; break;
         default: break;
      }
   }

   if( bLeft   && pLeft   != NULL ) *pLeft   = HBDOCK_AUTOHIDE_STRIP;
   if( bTop    && pTop    != NULL ) *pTop    = HBDOCK_AUTOHIDE_STRIP;
   if( bRight  && pRight  != NULL ) *pRight  = HBDOCK_AUTOHIDE_STRIP;
   if( bBottom && pBottom != NULL ) *pBottom = HBDOCK_AUTOHIDE_STRIP;
}

HB_DOCK_PANEL * hbDockManagerAutoHideHitTest(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   int i;

   if( pManager == NULL )
      return NULL;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE * pAutoHide =
         ( HB_DOCK_AUTOHIDE * ) hbDockArrayGet(
            &pManager->AutoHideManager.Panes,
            i );

      if( pAutoHide != NULL &&
          PtInRect( &pAutoHide->HiddenRect, pt ) )
         return pAutoHide->Panel;
   }

   return NULL;
}

/*
 * Etapa 76: pedido explicito -- el chequeo periodico de "el mouse
 * se fue del panel autohide expandido" (ver hbDockHostCheckAutoHideLeave
 * en hbdockhost.c) comparaba contra pPanel->Rect -- el rect ACTUAL,
 * que DURANTE la animacion de expansion es mas CHICO que el final
 * (va creciendo de a poco). Ese chequeo corre en un timer totalmente
 * INDEPENDIENTE del timer de la animacion -- si el chequeo corria en
 * medio de la animacion (mouse ya posicionado donde el panel va a
 * terminar, pero el panel todavia no crecio hasta ahi), el chequeo
 * concluia erroneamente "el mouse esta afuera" y colapsaba el panel
 * a mitad de camino -- confirmado con captura real: se ve expandirse
 * bien, y "se estabiliza" (colapsa) despues, con el mouse quieto.
 * Esta funcion expone el tamaño FINAL (VisibleRect) para comparar
 * contra ESE en vez del rect actual, sin importar en que punto de la
 * animacion este.
 */
BOOL hbDockManagerAutoHideGetVisibleRect(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   RECT * pRect )
{
   HB_DOCK_AUTOHIDE * pAutoHide;

   if( pManager == NULL || pPanel == NULL || pRect == NULL )
      return FALSE;

   pAutoHide = hbDockManagerFindAutoHide( pManager, pPanel );

   if( pAutoHide == NULL )
      return FALSE;

   *pRect = pAutoHide->VisibleRect;

   return TRUE;
}

/*
 * Etapa 55: pedido explicito -- al redimensionar la ventana
 * principal, HiddenRect/VisibleRect de cada panel autohidden
 * quedaban con los valores calculados en el momento en que se
 * repliego (una sola vez, dentro de hbDockManagerAutoHidePanel) --
 * nunca se volvian a calcular con las nuevas dimensiones, dejando
 * las pestañas "flotando" en posiciones que ya no correspondian al
 * tamaño actual de la ventana. Recorre todos los paneles autohidden
 * y recalcula sus rects -- llamar desde hbDockManagerLayout (que ya
 * corre en cada resize via ON RESIZE HBDockRefreshLayout).
 */
void hbDockManagerAutoHideRefreshRects(
   HB_DOCK_MANAGER * pManager )
{
   int i;

   if( pManager == NULL )
      return;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE * pAutoHide =
         ( HB_DOCK_AUTOHIDE * ) hbDockArrayGet(
            &pManager->AutoHideManager.Panes,
            i );

      HB_DOCK_SITE Site;
      int j;
      int nRankBefore;

      if( pAutoHide == NULL || pAutoHide->Panel == NULL )
         continue;

      Site = hbDockPanelGetDockSite( pAutoHide->Panel );

      /*
       * Etapa 55 (fix): rango de posicion entre los del MISMO lado
       * (cuantos ya aparecen ANTES que este en el array), no
       * "cuantos otros hay en total" (hbDockManagerCountAutoHideOnSite)
       * -- eso le daria el mismo numero a TODOS los del mismo lado
       * cuando ya estan todos presentes en el array (como aca), en
       * vez de un indice distinto y estable para cada uno.
       */
      nRankBefore = 0;

      for( j = 0; j < i; ++j )
      {
         HB_DOCK_AUTOHIDE * pOther =
            ( HB_DOCK_AUTOHIDE * ) hbDockArrayGet(
               &pManager->AutoHideManager.Panes,
               j );

         if( pOther != NULL &&
             pOther->Panel != NULL &&
             hbDockPanelGetDockSite( pOther->Panel ) == Site )
            nRankBefore++;
      }

      hbDockManagerCalcAutoHideRects(
         pManager,
         pAutoHide->Panel,
         Site,
         nRankBefore,
         &pAutoHide->HiddenRect,
         &pAutoHide->VisibleRect );
   }
}
