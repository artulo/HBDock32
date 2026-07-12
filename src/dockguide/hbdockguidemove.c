#include <windows.h>

#include "hbdockguidemove.h"

void hbDockGuideManagerMove(
   HB_DOCK_GUIDE_MANAGER * pManager )
{
   int i;

   if( pManager == NULL )
      return;

   for( i = 0; i < HB_DOCK_GUIDE_COUNT; ++i )
   {
      RECT * r =
         &pManager->Guides[ i ].Rect;

      MoveWindow(
         pManager->Guides[ i ].hWnd,
         r->left,
         r->top,
         r->right - r->left,
         r->bottom - r->top,
         TRUE );
   }
}