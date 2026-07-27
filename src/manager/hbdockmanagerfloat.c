#include <windows.h>

#include "hbdockmanagerfloat.h"

#include "hbdockmanagerundock.h"
#include "hbdockfloating.h"
#include "hbdockmonitor.h"

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

   if( !hbDockManagerUndock(
            pManager,
            pContainer ) )
      return FALSE;

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