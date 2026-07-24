#include <windows.h>

#include "hbdockdiamondhit.h"


HB_DOCK_DIAMOND_BUTTON hbDockDiamondHitTest(
   const HB_DOCK_DIAMOND * pDiamond,
   POINT pt )
{
   if( pDiamond == NULL )
      return HB_DIAMOND_NONE;


   if( PtInRect(
          &pDiamond->LeftRect,
          pt ) )
   {
      return HB_DIAMOND_LEFT;
   }


   if( PtInRect(
          &pDiamond->RightRect,
          pt ) )
   {
      return HB_DIAMOND_RIGHT;
   }


   if( PtInRect(
          &pDiamond->TopRect,
          pt ) )
   {
      return HB_DIAMOND_TOP;
   }


   if( PtInRect(
          &pDiamond->BottomRect,
          pt ) )
   {
      return HB_DIAMOND_BOTTOM;
   }


   if( PtInRect(
          &pDiamond->CenterRect,
          pt ) )
   {
      return HB_DIAMOND_CENTER;
   }


   return HB_DIAMOND_NONE;
}