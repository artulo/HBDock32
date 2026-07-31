#include <windows.h>

#include "hbdockautohideanimationmanagertick.h"

#include "hbdockautohideanimationtick.h"
#include "hbdockautohideslideengine.h"
#include "hbdockautohideanimationremove.h"
#include "hbdockautohideexpandcaption.h"
#include "hbdockcaption.h"
#include "hbdockmanager.h"
#include "hbdockmanagerlayout.h"

/*
 * Etapa 11: punto de entrada real para el timer del manager. Antes
 * de esta funcion, hbDockAutoHideAnimationTick (Etapa 5) hacia
 * avanzar cada panel en la cola, pero nada quitaba de la cola a los
 * que ya habian terminado de deslizar, y nada llamaba a
 * hbDockAutoHideAnimationTick desde ningun timer real -- todo el
 * motor quedaba girando en el vacio.
 *
 * Etapa 79: rediseno del overlay de AutoHide expandido (ver
 * hbdockautohideexpandcaption.c) -- el reposicionamiento durante la
 * animacion (incluyendo el cuadro final) ahora pasa siempre por
 * hbDockAutoHideOverlayReposition (llamada desde
 * hbDockAutoHideApplySlide, en cada tick), asi que este archivo ya
 * no necesita calcular rcCaption/rcContent ni mover la ventana del
 * panel a mano -- solo maneja el show/hide de la popup al empezar y
 * terminar.
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
      pManager,
      pDockManagerVoid );

   for( i = pManager->Count - 1; i >= 0; --i )
   {
      HB_DOCK_AUTOHIDE * pAutoHide;

      pAutoHide = pManager->pPanes[ i ];

      if( pAutoHide != NULL &&
          !hbDockAutoHideSlideRunning( pAutoHide ) )
      {
         /* Si termino de colapsar (deslizarse hacia HiddenRect), hay
          * que ocultar la ventana ahora y reparentar el contenido de
          * vuelta a la ventana principal (hbDockAutoHideExpandCaptionHide
          * hace ambas cosas). Si termino de expandirse, ya estaba
          * visible/reparentada desde que arranco el deslizamiento
          * (ver hbDockManagerAutoHideExpand) -- no hace falta nada
          * mas aca, hbDockAutoHideApplySlide ya la dejo en la
          * posicion final en el ultimo tick. */
         if( pAutoHide->SlideDirection < 0 &&
             pDockManager != NULL )
         {
            hbDockAutoHideExpandCaptionHide(
               pDockManager );
         }

         hbDockAutoHideAnimationRemovePane(
            pManager,
            pAutoHide );
      }
   }
}
