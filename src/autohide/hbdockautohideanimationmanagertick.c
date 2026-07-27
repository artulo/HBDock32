#include <windows.h>

#include "hbdockautohideanimationmanagertick.h"

#include "hbdockautohideanimationtick.h"
#include "hbdockautohideslideengine.h"
#include "hbdockautohideanimationremove.h"

/*
 * Etapa 11: punto de entrada real para el timer del manager. Antes
 * de esta funcion, hbDockAutoHideAnimationTick (Etapa 5) hacia
 * avanzar cada panel en la cola, pero nada quitaba de la cola a los
 * que ya habian terminado de deslizar, y nada llamaba a
 * hbDockAutoHideAnimationTick desde ningun timer real -- todo el
 * motor quedaba girando en el vacio.
 */

void hbDockAutoHideAnimationManagerTick(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager )
{
   int i;

   if( pManager == NULL )
      return;

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
          * hbDockManagerAutoHideExpand), no hace falta nada mas. */
         if( pAutoHide->SlideDirection < 0 &&
             pAutoHide->Panel != NULL &&
             pAutoHide->Panel->hWnd != NULL )
         {
            ShowWindow(
               pAutoHide->Panel->hWnd,
               SW_HIDE );
         }

         hbDockAutoHideAnimationRemovePane(
            pManager,
            pAutoHide );
      }
   }
}
