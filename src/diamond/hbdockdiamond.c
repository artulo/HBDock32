#include <windows.h>

#include "hbdockdiamond.h"

BOOL hbDockDiamondCreate(
   HB_DOCK_DIAMOND * pDiamond,
   HWND hOwner )
{
   if( pDiamond == NULL )
      return FALSE;

   ZeroMemory(
      pDiamond,
      sizeof( HB_DOCK_DIAMOND ) );

   pDiamond->hOwner = hOwner;

   return TRUE;
}

void hbDockDiamondDestroy(
   HB_DOCK_DIAMOND * pDiamond )
{
   if( pDiamond == NULL )
      return;

   pDiamond->Visible = FALSE;
}

void hbDockDiamondShow(
   HB_DOCK_DIAMOND * pDiamond )
{
   if( pDiamond == NULL )
      return;

   pDiamond->Visible = TRUE;
}

void hbDockDiamondHide(
   HB_DOCK_DIAMOND * pDiamond )
{
   if( pDiamond == NULL )
      return;

   pDiamond->Visible = FALSE;
}

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

HB_DOCK_DIAMOND_BUTTON hbDockDiamondHitTest(
   const HB_DOCK_DIAMOND * pDiamond,
   POINT pt )
{
   if( pDiamond == NULL )
      return HB_DIAMOND_NONE;

   if( PtInRect( &pDiamond->LeftRect, pt ) )
      return HB_DIAMOND_LEFT;

   if( PtInRect( &pDiamond->RightRect, pt ) )
      return HB_DIAMOND_RIGHT;

   if( PtInRect( &pDiamond->TopRect, pt ) )
      return HB_DIAMOND_TOP;

   if( PtInRect( &pDiamond->BottomRect, pt ) )
      return HB_DIAMOND_BOTTOM;

   if( PtInRect( &pDiamond->CenterRect, pt ) )
      return HB_DIAMOND_CENTER;

   return HB_DIAMOND_NONE;
}