#include <windows.h>

#include "hbdockautohideslideapply.h"
#include "hbdockpaneldock.h"
#include "hbdockmanager.h"
#include "hbdockautohideexpandcaption.h"

/*
 * Nota de estabilizacion (Etapa 11): esta funcion siempre movia el
 * panel directo a VisibleRect, sin importar SlidePosition/SlideSize
 * -- es decir, todo el motor de animacion (Etapa 5) calculaba una
 * posicion intermedia que despues nunca se usaba para nada; el
 * panel igual saltaba de golpe. Se corrige para interpolar de
 * verdad entre HiddenRect y VisibleRect segun el avance actual.
 *
 * Etapa 61 (fix): interpolar las 4 coordenadas por igual (como se
 * hacia hasta ahora) andaba bien SOLO mientras HiddenRect abarcara
 * todo el ancho/alto a lo largo del borde (como era antes de la
 * Etapa 53) -- desde que HiddenRect pasó a ser una franjita angosta
 * de solo 130px para permitir apilar varios autohides en el mismo
 * lado, HiddenRect y VisibleRect difieren tambien en la dimension
 * A LO LARGO DEL BORDE (no solo en profundidad), y interpolar esa
 * dimension tambien hacia que el panel se "desdoblara" en dos
 * direcciones a la vez en vez de deslizar limpio. Ahora solo se
 * interpola la coordenada de PROFUNDIDAD (perpendicular al borde);
 * las otras 3 quedan fijas en los valores de VisibleRect desde el
 * primer frame de la animacion.
 *
 * Etapa 79: rediseno -- en vez de mover pAutoHide->Panel->hWnd
 * directo (compitiendo por z-order contra sus hermanos acoplados,
 * via BringWindowToTop/HWND_TOPMOST -- ninguno confiable del todo),
 * ahora se convierte el rect a coordenadas de PANTALLA y se
 * reposiciona la popup de overlay (ver hbdockautohideexpandcaption.c)
 * -- la popup, al ser una ventana de nivel superior genuina, tiene
 * z-order confiable de forma nativa por encima de TODAS las
 * ventanas hijas de la principal, sin necesidad de "pelear" el
 * orden. El contenido real (reparentado adentro de la popup) se
 * reposiciona solo, como parte de ese reposicionamiento.
 */

void hbDockAutoHideApplySlide(
   HB_DOCK_AUTOHIDE * pAutoHide,
   void * pManagerVoid )
{
   RECT rc;
   RECT rcScreen;
   double t;
   HB_DOCK_SITE Site;
   HB_DOCK_MANAGER * pManager;

   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   pManager = ( HB_DOCK_MANAGER * ) pManagerVoid;

   if( pManager == NULL )
      return;

   if( pAutoHide->SlideSize <= 0 )
   {
      t = 1.0;
   }
   else
   {
      t = ( double ) pAutoHide->SlidePosition /
          ( double ) pAutoHide->SlideSize;
   }

   if( t < 0.0 )
      t = 0.0;

   if( t > 1.0 )
      t = 1.0;

   Site =
      hbDockPanelGetDockSite(
         pAutoHide->Panel );

   switch( Site )
   {
      case HB_DOCKSITE_LEFT:

         rc.top    = pAutoHide->VisibleRect.top;
         rc.bottom = pAutoHide->VisibleRect.bottom;
         rc.left   = pAutoHide->VisibleRect.left;

         rc.right =
            pAutoHide->HiddenRect.right +
            ( LONG ) ( ( pAutoHide->VisibleRect.right -
                         pAutoHide->HiddenRect.right ) * t );
         break;

      case HB_DOCKSITE_RIGHT:

         rc.top    = pAutoHide->VisibleRect.top;
         rc.bottom = pAutoHide->VisibleRect.bottom;
         rc.right  = pAutoHide->VisibleRect.right;

         rc.left =
            pAutoHide->HiddenRect.left +
            ( LONG ) ( ( pAutoHide->VisibleRect.left -
                         pAutoHide->HiddenRect.left ) * t );
         break;

      case HB_DOCKSITE_TOP:

         rc.left   = pAutoHide->VisibleRect.left;
         rc.right  = pAutoHide->VisibleRect.right;
         rc.top    = pAutoHide->VisibleRect.top;

         rc.bottom =
            pAutoHide->HiddenRect.bottom +
            ( LONG ) ( ( pAutoHide->VisibleRect.bottom -
                         pAutoHide->HiddenRect.bottom ) * t );
         break;

      case HB_DOCKSITE_BOTTOM:
      default:

         rc.left   = pAutoHide->VisibleRect.left;
         rc.right  = pAutoHide->VisibleRect.right;
         rc.bottom = pAutoHide->VisibleRect.bottom;

         rc.top =
            pAutoHide->HiddenRect.top +
            ( LONG ) ( ( pAutoHide->VisibleRect.top -
                         pAutoHide->HiddenRect.top ) * t );
         break;
   }

   /*
    * Etapa 77: piso minimo -- sin esto, el primer cuadro de la
    * animacion (t=0) podia calcular un ancho/alto de exactamente
    * CERO (con el offset de la Etapa 74), lo que corrompia el
    * estado interno de controles embebidos (ej. un TWBrowse).
    */
   if( rc.right - rc.left < 10 )
   {
      if( Site == HB_DOCKSITE_LEFT )
         rc.right = rc.left + 10;
      else if( Site == HB_DOCKSITE_RIGHT )
         rc.left = rc.right - 10;
   }

   if( rc.bottom - rc.top < 10 )
   {
      if( Site == HB_DOCKSITE_TOP )
         rc.bottom = rc.top + 10;
      else if( Site == HB_DOCKSITE_BOTTOM )
         rc.top = rc.bottom - 10;
   }

   pAutoHide->Panel->Rect = rc;

   /*
    * Etapa 79: convertir a coordenadas de PANTALLA (la popup se
    * posiciona en pantalla, no relativo a un padre) y reposicionar
    * el overlay -- esto tambien reposiciona el contenido reparentado
    * adentro, automaticamente.
    */
   rcScreen = rc;

   MapWindowPoints(
      pManager->hMainWnd,
      NULL,
      ( POINT * ) &rcScreen,
      2 );

   hbDockAutoHideOverlayReposition(
      pManager,
      &rcScreen );
}
