#include <windows.h>

#include "hbdockdiamond.h"

void hbDockDiamondMove(
   HB_DOCK_DIAMOND * pDiamond,
   POINT pt )
{
   LONG Size;

   if( pDiamond == NULL )
      return;

   Size = 28;

   SetRect(
      &pDiamond->CenterRect,
      pt.x - Size / 2,
      pt.y - Size / 2,
      pt.x + Size / 2,
      pt.y + Size / 2 );

   pDiamond->LeftRect = pDiamond->CenterRect;
   OffsetRect(
      &pDiamond->LeftRect,
      -40,
      0 );

   pDiamond->RightRect = pDiamond->CenterRect;
   OffsetRect(
      &pDiamond->RightRect,
      40,
      0 );

   pDiamond->TopRect = pDiamond->CenterRect;
   OffsetRect(
      &pDiamond->TopRect,
      0,
      -40 );

   pDiamond->BottomRect = pDiamond->CenterRect;
   OffsetRect(
      &pDiamond->BottomRect,
      0,
      40 );
}