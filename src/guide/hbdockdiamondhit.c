#include <windows.h>

#include "hbdockdiamondhit.h"

HB_DOCK_DIAMOND_PART
hbDockDiamondHitTest(
   HB_DOCK_DIAMOND * pDiamond,
   POINT pt )
{
   if( PtInRect(
      &pDiamond->Left,
      pt ) )
      return HB_DIAMOND_LEFT;

   if( PtInRect(
      &pDiamond->Right,
      pt ) )
      return HB_DIAMOND_RIGHT;

   if( PtInRect(
      &pDiamond->Top,
      pt ) )
      return HB_DIAMOND_TOP;

   if( PtInRect(
      &pDiamond->Bottom,
      pt ) )
      return HB_DIAMOND_BOTTOM;

   if( PtInRect(
      &pDiamond->Center,
      pt ) )
      return HB_DIAMOND_CENTER;

   return HB_DIAMOND_NONE;
}