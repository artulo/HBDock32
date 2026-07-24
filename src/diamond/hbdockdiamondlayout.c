#include <windows.h>

#include "hbdockdiamondlayout.h"


void hbDockDiamondLayout(
   HB_DOCK_DIAMOND * pDiamond,
   const RECT * pRect )
{
   RECT rc;
   int cx;
   int cy;
   int x;
   int y;


   if( pDiamond == NULL )
      return;


   if( pRect == NULL )
      return;


   rc = *pRect;


   cx =
      rc.right -
      rc.left;


   cy =
      rc.bottom -
      rc.top;


   x =
      rc.left +
      ( cx / 2 );


   y =
      rc.top +
      ( cy / 2 );


   /*
    * Centro
    */

   SetRect(
      &pDiamond->CenterRect,
      x - 20,
      y - 20,
      x + 20,
      y + 20 );


   /*
    * Izquierda
    */

   SetRect(
      &pDiamond->LeftRect,
      x - 80,
      y - 20,
      x - 40,
      y + 20 );


   /*
    * Derecha
    */

   SetRect(
      &pDiamond->RightRect,
      x + 40,
      y - 20,
      x + 80,
      y + 20 );


   /*
    * Arriba
    */

   SetRect(
      &pDiamond->TopRect,
      x - 20,
      y - 80,
      x + 20,
      y - 40 );


   /*
    * Abajo
    */

   SetRect(
      &pDiamond->BottomRect,
      x - 20,
      y + 40,
      x + 20,
      y + 80 );


   pDiamond->Rect = rc;
}