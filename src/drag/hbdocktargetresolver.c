#include <windows.h>

#include "hbdocktargetresolver.h"

BOOL hbDockResolveTarget(
      HWND hHost,
      POINT pt,
      HB_DOCK_TARGET_INFO * pInfo )
{
   RECT rc;

   GetClientRect(
      hHost,
      &rc );

   pInfo->hTarget = hHost;

   pInfo->PreviewRect = rc;

   if( pt.x < rc.right / 4 )
   {
      pInfo->Target =
         HB_DOCK_TARGET_LEFT;
   }
   else if( pt.x > rc.right * 3 / 4 )
   {
      pInfo->Target =
         HB_DOCK_TARGET_RIGHT;
   }
   else if( pt.y < rc.bottom / 4 )
   {
      pInfo->Target =
         HB_DOCK_TARGET_TOP;
   }
   else if( pt.y > rc.bottom * 3 / 4 )
   {
      pInfo->Target =
         HB_DOCK_TARGET_BOTTOM;
   }
   else
   {
      pInfo->Target =
         HB_DOCK_TARGET_CENTER;
   }

   return TRUE;
}