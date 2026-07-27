#include <windows.h>

#include "hbdockautohideslideapply.h"

/*
 * Nota de estabilizacion (Etapa 11): esta funcion siempre movia el
 * panel directo a VisibleRect, sin importar SlidePosition/SlideSize
 * -- es decir, todo el motor de animacion (Etapa 5) calculaba una
 * posicion intermedia que despues nunca se usaba para nada; el
 * panel igual saltaba de golpe. Se corrige para interpolar de
 * verdad entre HiddenRect y VisibleRect segun el avance actual.
 */

void hbDockAutoHideApplySlide(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   RECT rc;
   double t;

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

   rc.left =
      pAutoHide->HiddenRect.left +
      ( LONG ) ( ( pAutoHide->VisibleRect.left -
                   pAutoHide->HiddenRect.left ) * t );

   rc.top =
      pAutoHide->HiddenRect.top +
      ( LONG ) ( ( pAutoHide->VisibleRect.top -
                   pAutoHide->HiddenRect.top ) * t );

   rc.right =
      pAutoHide->HiddenRect.right +
      ( LONG ) ( ( pAutoHide->VisibleRect.right -
                   pAutoHide->HiddenRect.right ) * t );

   rc.bottom =
      pAutoHide->HiddenRect.bottom +
      ( LONG ) ( ( pAutoHide->VisibleRect.bottom -
                   pAutoHide->HiddenRect.bottom ) * t );

   pAutoHide->Panel->Rect = rc;

   MoveWindow(
      pAutoHide->Panel->hWnd,
      rc.left,
      rc.top,
      rc.right - rc.left,
      rc.bottom - rc.top,
      TRUE );
}