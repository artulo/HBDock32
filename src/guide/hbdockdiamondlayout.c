#include <windows.h>

#include "hbdockdiamondlayout.h"

#define PART 32
#define GAP 6

void hbDockDiamondLayout(
   HB_DOCK_DIAMOND * pDiamond,
   const RECT * pRect )
{
   int cx;
   int cy;

   cx =
      ( pRect->left +
        pRect->right ) / 2;

   cy =
      ( pRect->top +
        pRect->bottom ) / 2;

   SetRect(
      &pDiamond->Center,
      cx - PART/2,
      cy - PART/2,
      cx + PART/2,
      cy + PART/2 );

   SetRect(
      &pDiamond->Left,
      cx - PART - GAP - PART/2,
      cy - PART/2,
      cx - GAP - PART/2,
      cy + PART/2 );

   SetRect(
      &pDiamond->Right,
      cx + GAP + PART/2,
      cy - PART/2,
      cx + PART + GAP + PART/2,
      cy + PART/2 );

   SetRect(
      &pDiamond->Top,
      cx - PART/2,
      cy - PART - GAP - PART/2,
      cx + PART/2,
      cy - GAP - PART/2 );

   SetRect(
      &pDiamond->Bottom,
      cx - PART/2,
      cy + GAP + PART/2,
      cx + PART/2,
      cy + PART + GAP + PART/2 );
}