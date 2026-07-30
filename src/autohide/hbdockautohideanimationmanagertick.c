#include <windows.h>

#include "hbdockautohideanimationmanagertick.h"

#include "hbdockautohideanimationtick.h"
#include "hbdockautohideslideengine.h"
#include "hbdockautohideanimationremove.h"
#include "hbdockautohideexpandcaption.h"
#include "hbdockcaption.h"
#include "hbdockmanager.h"

/*
 * Etapa 11: punto de entrada real para el timer del manager. Antes
 * de esta funcion, hbDockAutoHideAnimationTick (Etapa 5) hacia
 * avanzar cada panel en la cola, pero nada quitaba de la cola a los
 * que ya habian terminado de deslizar, y nada llamaba a
 * hbDockAutoHideAnimationTick desde ningun timer real -- todo el
 * motor quedaba girando en el vacio.
 */

void hbDockAutoHideAnimationManagerTick(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager,
   void * pDockManagerVoid )
{
   int i;
   HB_DOCK_MANAGER * pDockManager;

   if( pManager == NULL )
      return;

   pDockManager = ( HB_DOCK_MANAGER * ) pDockManagerVoid;

   /* Recorrer de atras para adelante: hbDockAutoHideAnimationRemovePane
    * corre los elementos siguientes un lugar hacia atras, asi que
    * sacar de adelante hacia atras evita saltearse el que ocupa el
    * lugar del que se acaba de quitar. */

   hbDockAutoHideAnimationTick(
      pManager );

   for( i = pManager->Count - 1; i >= 0; --i )
   {
      HB_DOCK_AUTOHIDE * pAutoHide;

      pAutoHide = pManager->pPanes[ i ];

      if( pAutoHide != NULL &&
          !hbDockAutoHideSlideRunning( pAutoHide ) )
      {
         /* Si termino de colapsar (deslizarse hacia HiddenRect), hay
          * que ocultar la ventana ahora -- ApplySlide solo la mueve,
          * nunca la esconde. Si termino de expandirse, ya estaba
          * visible desde que arranco el deslizamiento (Etapa 11,
          * hbDockManagerAutoHideExpand). */
         if( pAutoHide->SlideDirection < 0 &&
             pAutoHide->Panel != NULL &&
             pAutoHide->Panel->hWnd != NULL )
         {
            ShowWindow(
               pAutoHide->Panel->hWnd,
               SW_HIDE );

            /*
             * Etapa 60: sin esto, la ventana de caption mostrada al
             * expandir (Etapa 59) quedaba visible para siempre --
             * solo se ocultaba en el camino NO animado de colapsar y
             * en los clicks de pin/"x" del caption mismo, nunca aca
             * (el colapso automatico animado, al sacar el mouse, que
             * es el camino que realmente se usa con Animation=TRUE,
             * el default).
             */
            if( pDockManager != NULL )
               hbDockAutoHideExpandCaptionHide(
                  pDockManager );
         }
         else if( pAutoHide->SlideDirection >= 0 &&
                  pAutoHide->Panel != NULL &&
                  pAutoHide->Panel->hWnd != NULL &&
                  pDockManager != NULL )
         {
            /*
             * Etapa 59: termino de EXPANDIRSE (camino animado) --
             * reservar HBDOCK_CAPTION_HEIGHT arriba para el caption
             * y mostrarlo, mismo tratamiento que ya tenia el camino
             * NO animado (Etapa 58) -- sin esto, con Animation=TRUE
             * (el default), el caption nunca aparecia.
             */
            RECT rcCaption;
            RECT rcContent;

            rcCaption = pAutoHide->Panel->Rect;
            rcCaption.bottom = rcCaption.top + HBDOCK_CAPTION_HEIGHT;

            rcContent = pAutoHide->Panel->Rect;
            rcContent.top += HBDOCK_CAPTION_HEIGHT;

            if( rcContent.top > rcContent.bottom )
               rcContent.top = rcContent.bottom;

            MoveWindow(
               pAutoHide->Panel->hWnd,
               rcContent.left,
               rcContent.top,
               rcContent.right  - rcContent.left,
               rcContent.bottom - rcContent.top,
               TRUE );

            hbDockAutoHideExpandCaptionShow(
               pDockManager,
               pAutoHide->Panel,
               &rcCaption );
         }

         hbDockAutoHideAnimationRemovePane(
            pManager,
            pAutoHide );
      }
   }
}
