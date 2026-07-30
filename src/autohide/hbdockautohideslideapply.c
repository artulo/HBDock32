#include <windows.h>

#include "hbdockautohideslideapply.h"
#include "hbdockpaneldock.h"

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
 * direcciones a la vez en vez de deslizar limpio -- confirmado con
 * captura real, mas notorio en TOP pero el mismo bug afecta a
 * cualquier lado. Ahora solo se interpola la coordenada de
 * PROFUNDIDAD (perpendicular al borde, la que realmente crece al
 * expandirse); las otras 3 quedan fijas en los valores de
 * VisibleRect desde el primer frame de la animacion.
 */

void hbDockAutoHideApplySlide(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   RECT rc;
   double t;
   HB_DOCK_SITE Site;

   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
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

   pAutoHide->Panel->Rect = rc;

   MoveWindow(
      pAutoHide->Panel->hWnd,
      rc.left,
      rc.top,
      rc.right - rc.left,
      rc.bottom - rc.top,
      TRUE );
}