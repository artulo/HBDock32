#include <windows.h>

#include "hbdockguidemove.h"


void hbDockGuideManagerMove(
   HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt )
{
   int dx;
   int dy;


   if( pManager == NULL )
      return;


   /*
    * Desplazamiento desde la posición actual.
    */

   dx = pt.x;
   dy = pt.y;


   /*
    * Mover guía izquierda
    */

   OffsetRect(
      &pManager->Left.Rect,
      dx,
      dy );


   /*
    * Mover guía derecha
    */

   OffsetRect(
      &pManager->Right.Rect,
      dx,
      dy );


   /*
    * Mover guía superior
    */

   OffsetRect(
      &pManager->Top.Rect,
      dx,
      dy );


   /*
    * Mover guía inferior
    */

   OffsetRect(
      &pManager->Bottom.Rect,
      dx,
      dy );


   /*
    * Mover guía central
    */

   OffsetRect(
      &pManager->Center.Rect,
      dx,
      dy );
}