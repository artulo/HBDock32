#include <windows.h>

#include "hbdockdocksite.h"

void hbDockSiteInit(
   HB_DOCK_DOCKSITE * pSite )
{
   if( pSite == NULL )
      return;

   ZeroMemory(
      pSite,
      sizeof( HB_DOCK_DOCKSITE ) );
}

void hbDockSiteCalc(
   HB_DOCK_DOCKSITE * pSite,
   HB_DOCK_NODE * pNode,
   HB_DOCK_SITE Site )
{
   RECT rc;
   int w;
   int h;

   if( pSite == NULL || pNode == NULL )
      return;

   rc = pNode->Rect;

   w = ( rc.right - rc.left ) / 3;
   h = ( rc.bottom - rc.top ) / 3;

   pSite->Node = pNode;
   pSite->Site = Site;

   switch( Site )
   {
      case HB_DOCKSITE_LEFT:

         rc.right = rc.left + w;
         break;

      case HB_DOCKSITE_RIGHT:

         rc.left = rc.right - w;
         break;

      case HB_DOCKSITE_TOP:

         rc.bottom = rc.top + h;
         break;

      case HB_DOCKSITE_BOTTOM:

         rc.top = rc.bottom - h;
         break;

      case HB_DOCKSITE_CENTER:

         rc.left += w;
         rc.right -= w;
         rc.top += h;
         rc.bottom -= h;
         break;

      default:
         SetRectEmpty( &rc );
   }

   pSite->Rect = rc;
}

int hbDockSiteHitTest(
   const HB_DOCK_DOCKSITE * pSite,
   POINT pt )
{
   if( pSite == NULL )
      return 0;

   return PtInRect(
      ( RECT * ) &pSite->Rect,
      pt );
}