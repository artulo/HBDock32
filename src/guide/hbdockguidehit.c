#include <windows.h>

#include "hbdockguidehit.h"

HB_DOCK_GUIDE *
hbDockGuideManagerHitTest(
   HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt )
{
   int i;

   if( pManager == NULL )
      return NULL;

   for( i = 0; i < HB_DOCK_GUIDE_COUNT; ++i )
   {
      if( PtInRect(
             &pManager->Guides[ i ].Rect,
             pt ) )
      {
         return &pManager->Guides[ i ];
      }
   }

   return NULL;
}