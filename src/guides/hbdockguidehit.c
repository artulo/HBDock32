#include <windows.h>

#include "hbdockguidehit.h"



HB_DOCK_GUIDE_TYPE hbDockGuideManagerHitTest(
   const HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt )
{
   if( pManager == NULL )
      return HB_GUIDE_NONE;


   if( PtInRect(
          &pManager->Left.Rect,
          pt ) )
   {
      return HB_GUIDE_LEFT;
   }


   if( PtInRect(
          &pManager->Right.Rect,
          pt ) )
   {
      return HB_GUIDE_RIGHT;
   }


   if( PtInRect(
          &pManager->Top.Rect,
          pt ) )
   {
      return HB_GUIDE_TOP;
   }


   if( PtInRect(
          &pManager->Bottom.Rect,
          pt ) )
   {
      return HB_GUIDE_BOTTOM;
   }


   if( PtInRect(
          &pManager->Center.Rect,
          pt ) )
   {
      return HB_GUIDE_CENTER;
   }


   return HB_GUIDE_NONE;
}