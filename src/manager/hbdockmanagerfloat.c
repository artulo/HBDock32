#include <windows.h>

#include "hbdockmanagerfloat.h"

#include "hbdockmanagerundock.h"
#include "hbdockfloating.h"
#include "hbdockmonitor.h"
#include "hbdockmanagerdrag.h"
#include "hbdockdragcontroller.h"
#include "hbdockdragpreview.h"
#include "hbdockmanagerdock.h"
#include "hbdockmanagerlayout.h"

/*
 * Etapa 44 (REVERTIDO -- ver conversacion con Claude): la Etapa 43
 * deshabilitaba el contenido de los paneles acoplados via
 * EnableWindow mientras habia flotantes abiertos -- pero eso rompio
 * los clicks (confirmado: los botones seguian pintando el hover pero
 * no respondian). Pedido explicito de cambiar a activacion por
 * HOVER en vez de deshabilitar nada: ver hbdockmanagerkeepontop.c
 * (WM_MOUSEMOVE de la ventana principal) y hbdockfloating.c
 * (WM_MOUSEMOVE del flotante) -- cada uno se auto-activa cuando el
 * mouse entra, sin tocar EnableWindow en ningun lado.
 */

BOOL hbDockManagerFloat(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_CONTAINER * pContainer,
   const RECT * pRect )
{
   HB_DOCK_PANEL * pPanel;
   RECT rcAdjusted;
   RECT rcWorkArea;
   POINT ptCenter;

   if( pManager == NULL )
      return FALSE;

   if( pContainer == NULL )
      return FALSE;

   pPanel = pContainer->TabGroup.pPanel;

   if( pPanel == NULL )
      return FALSE;

   if( pPanel->pFloating == NULL )
      return FALSE;

   /*
    * Etapa 21: mismo bug y mismo fix que la Etapa 14
    * (hbDockManagerDockPanel/TabifyPanel) -- esto llamaba a
    * hbDockManagerUndock directo sobre pContainer, la version a
    * nivel CONTENEDOR, que saca el contenedor ENTERO del arbol. Si
    * el panel que se esta flotando comparte contenedor con otro
    * (tabificado, por ejemplo via el diamante o "Tab al centro"), el
    * companero de pestaña se iba de arrastre: quedaba huerfano, sin
    * que nadie lo vuelva a mover/ocultar nunca mas -- la misma
    * corrupcion que causaba la pantalla en blanco / ventana principal
    * sin responder, confirmada esta vez con Float en vez de Dock.
    * hbDockManagerUndockPanel SI distingue "sacar solo este panel de
    * la pestaña" de "sacar el contenedor entero".
    */
   hbDockManagerUndockPanel(
      pManager,
      pPanel );

   pPanel->pContainer = NULL;

   /* Nota de estabilizacion (Etapa 10): segunda capa de seguridad de
    * multi-monitor, por si algun llamador futuro (por ejemplo, una
    * restauracion de layout guardado) le pasa un pRect directo sin
    * pasar por hbDockManagerFloatPanel (que ya clampea usando el
    * punto exacto del drop). Se usa el centro del rect para ubicar
    * el monitor correcto. */
   rcAdjusted = *pRect;

   ptCenter.x = ( rcAdjusted.left + rcAdjusted.right ) / 2;
   ptCenter.y = ( rcAdjusted.top + rcAdjusted.bottom ) / 2;

   if( hbDockMonitorGetWorkAreaAtPoint(
          ptCenter,
          &rcWorkArea ) )
   {
      hbDockMonitorClampRect(
         &rcAdjusted,
         &rcWorkArea );
   }

   hbDockFloatingMove(
      pPanel->pFloating,
      &rcAdjusted );

   hbDockFloatingShow(
      pPanel->pFloating,
      SW_SHOW );

   pPanel->Floating = TRUE;

   /*
    * Etapa 42: contador de flotantes abiertos -- ya no deshabilita
    * nada (ver Etapa 44), pero se mantiene por si sirve para otra
    * cosa mas adelante (por ejemplo, saber si hay algun flotante
    * abierto).
    */
   pManager->FloatingCount++;

   return TRUE;
}

/*
 * Nota de estabilizacion (Etapa 8): esta funcion estaba declarada en
 * el header y se llama de verdad desde hbDockManagerEndDrag (Etapa 4,
 * el camino de "soltar el panel fuera de cualquier guia = flotar")
 * pero no tenia ninguna implementacion en todo el arbol -- otro
 * "unresolved external" esperando a pasar, del mismo tipo que
 * hbDockManagerBeginDrag (Etapa 4) y hbDockGuideManagerCreate (Etapa 6).
 *
 * Ademas, revisando hbDockManagerFloat (arriba) encontre que exige
 * pPanel->pFloating != NULL -- pero NADA en todo el proyecto asignaba
 * ese campo nunca, asi que aunque esta funcion hubiera existido,
 * flotar un panel habria fallado siempre. Se agrega la creacion
 * perezosa de HB_DOCK_FLOATING (via hbDockFloatingCreate, que ya
 * existia y funciona) la primera vez que un panel se flota.
 */
void hbDockManagerFloatPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   POINT pt )
{
   RECT rc;
   int cx;
   int cy;

   if( pManager == NULL )
      return;

   if( pPanel == NULL )
      return;

   /*
    * Nota de estabilizacion: pt llega en coordenadas de CLIENTE de
    * la ventana principal (asi es como se calcula pPanel->Rect, y
    * asi llegan los mensajes de mouse durante un arrastre) -- pero
    * la ventana flotante es una ventana de nivel superior (WS_POPUP),
    * que necesita coordenadas de PANTALLA para posicionarse bien
    * con MoveWindow/CreateWindowEx. Sin esta conversion, la ventana
    * flotante terminaba posicionada con los numeros de coordenada
    * equivocados -- en la practica, aparecia superpuesta "adentro"
    * de la ventana principal en vez de flotar libre en la pantalla.
    */
   if( pManager->hMainWnd != NULL )
      ClientToScreen(
         pManager->hMainWnd,
         &pt );

   if( pPanel->pFloating == NULL )
   {
      pPanel->pFloating =
         ( HB_DOCK_FLOATING * )
         LocalAlloc(
            LPTR,
            sizeof( HB_DOCK_FLOATING ) );

      if( pPanel->pFloating == NULL )
         return;

      if( !hbDockFloatingCreate(
               pPanel->pFloating,
               GetModuleHandle( NULL ),
               pPanel,
               pManager->hMainWnd ) )
      {
         LocalFree(
            pPanel->pFloating );

         pPanel->pFloating = NULL;

         return;
      }

      /* Etapa 42 */
      pPanel->pFloating->pManager = pManager;
   }

   cx = pPanel->Rect.right - pPanel->Rect.left;
   cy = pPanel->Rect.bottom - pPanel->Rect.top;

   if( cx < pPanel->MinWidth )
      cx = pPanel->MinWidth;

   if( cy < pPanel->MinHeight )
      cy = pPanel->MinHeight;

   SetRect(
      &rc,
      pt.x,
      pt.y,
      pt.x + cx,
      pt.y + cy );

   /* Nota de estabilizacion (Etapa 10): sin esto, si pt cae cerca
    * del borde de un monitor (o de uno con la barra de tareas en un
    * lado distinto al del monitor principal), la ventana flotante
    * podia terminar mitad afuera del area visible. Se ajusta al
    * area de trabajo real del monitor que esta debajo del punto
    * donde se solto el panel. */
   {
      RECT rcWorkArea;

      if( hbDockMonitorGetWorkAreaAtPoint(
             pt,
             &rcWorkArea ) )
      {
         hbDockMonitorClampRect(
            &rc,
            &rcWorkArea );
      }
   }

   hbDockManagerFloat(
      pManager,
      pPanel->pContainer,
      &rc );
}

/*
 * Etapa 42: contraparte de la Etapa 42 en hbDockManagerFloat -- se
 * llama desde donde sea que un flotante deje de estar visible
 * (WM_DESTROY al cerrar con la "x", o "Restaurar"/redock). Decrementa
 * el contador y, si llega a 0 (ultimo flotante cerrado), rehabilita
 * la ventana principal.
 */
void hbDockManagerFloatClosed(
   void * pManagerVoid )
{
   HB_DOCK_MANAGER * pManager;

   if( pManagerVoid == NULL )
      return;

   pManager = ( HB_DOCK_MANAGER * ) pManagerVoid;

   if( pManager->FloatingCount > 0 )
      pManager->FloatingCount--;
}

/*
 * Etapa 47: pedido explicito -- un panel ya flotante debia poder
 * redockearse arrastrandolo hacia los diamantes, igual que un panel
 * acoplado normal. Antes de esto, la ventana flotante (WS_POPUP
 * nativa) no tenia NINGUN enganche de mouse/drag propio -- arrastrar
 * su titulo solo la movia como ventana nativa de Windows, sin pasar
 * nunca por hbDockDragController/hbDockGuideManager.
 *
 * Estas 3 funciones reutilizan el MISMO sistema de drag/guias que ya
 * usa un panel acoplado (hbDockManagerBeginDrag/DragMove, y el mismo
 * hit-test de guia HB_GUIDE_NONE/otro), llamadas desde
 * WM_ENTERSIZEMOVE/WM_MOVING/WM_EXITSIZEMOVE de la ventana flotante
 * (ver hbdockfloating.c) -- Windows no manda WM_MOUSEMOVE normal
 * durante el arrastre nativo del titulo, por eso se usa GetCursorPos
 * en su lugar, con estos wrappers convirtiendo a coordenadas de
 * cliente de la ventana principal antes de llamar al sistema comun.
 */
void hbDockManagerFloatDragBegin(
   void * pManagerVoid,
   HB_DOCK_PANEL * pPanel,
   POINT ptScreen )
{
   HB_DOCK_MANAGER * pManager;
   POINT pt;

   pManager = ( HB_DOCK_MANAGER * ) pManagerVoid;

   if( pManager == NULL || pPanel == NULL )
      return;

   pt = ptScreen;

   if( pManager->hMainWnd != NULL )
      ScreenToClient(
         pManager->hMainWnd,
         &pt );

   hbDockManagerBeginDrag(
      pManager,
      pPanel,
      pt );
}

void hbDockManagerFloatDragMove(
   void * pManagerVoid,
   POINT ptScreen )
{
   HB_DOCK_MANAGER * pManager;
   POINT pt;

   pManager = ( HB_DOCK_MANAGER * ) pManagerVoid;

   if( pManager == NULL )
      return;

   pt = ptScreen;

   if( pManager->hMainWnd != NULL )
      ScreenToClient(
         pManager->hMainWnd,
         &pt );

   hbDockManagerDragMove(
      pManager,
      pt );
}

void hbDockManagerFloatDragEnd(
   void * pManagerVoid,
   POINT ptScreen )
{
   HB_DOCK_MANAGER * pManager;
   POINT pt;
   HB_DOCK_PANEL * pPanel;
   HB_DOCK_GUIDE_TYPE Guide;
   HB_DOCK_FLOATING * pOldFloating;

   pManager = ( HB_DOCK_MANAGER * ) pManagerVoid;

   if( pManager == NULL )
      return;

   pt = ptScreen;

   if( pManager->hMainWnd != NULL )
      ScreenToClient(
         pManager->hMainWnd,
         &pt );

   if( !hbDockDragIsDragging(
          pManager->pDragController ) )
      return;

   pPanel =
      hbDockDragGetPanel(
         pManager->pDragController );

   Guide =
      hbDockDragHitTest(
         pManager->pDragController );

   hbDockDragControllerEnd(
      pManager->pDragController );

   hbDockDragPreviewHide(
      pManager );

   pManager->Dragging = FALSE;

   if( pPanel == NULL )
      return;

   pPanel->Visible = TRUE;

   if( Guide == HB_GUIDE_NONE )
   {
      /*
       * Se solto fuera de cualquier guia -- sigue flotando donde
       * Windows ya lo dejo (drag nativo del titulo de la ventana
       * flotante); no hay nada mas que hacer aca.
       */
      return;
   }

   /*
    * Se solto sobre una guia -- redockear. Hay que destruir la
    * ventana flotante VIEJA primero (reparenta pPanel->hWnd de
    * vuelta al owner y limpia pPanel->pFloating/Floating -- ver
    * WM_DESTROY en hbdockfloating.c) ANTES de acoplar, porque
    * hbDockManagerDockPanel va a reparentar pPanel->hWnd hacia donde
    * corresponda en el arbol -- si no se destruye antes, quedaria un
    * marco de ventana flotante vacio flotando en la pantalla, sin
    * nada adentro.
    */
   pOldFloating = pPanel->pFloating;

   if( pOldFloating != NULL )
      hbDockFloatingDestroy(
         pOldFloating );

   hbDockManagerDockPanel(
      pManager,
      pPanel,
      Guide );

   hbDockManagerLayout(
      pManager );
}