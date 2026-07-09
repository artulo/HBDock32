#include "hbdockfloatingfind.h"

HB_DOCK_FLOATING_FRAME * hbDockFloatingFindByWindow(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HWND hWnd )
{
   int i;

   if( pManager == NULL )
      return NULL;

   for( i = 0; i < pManager->Frames.Count; ++i )
   {
      HB_DOCK_FLOATING_FRAME * pFrame;

      pFrame =
         ( HB_DOCK_FLOATING_FRAME * )
         hbDockArrayGet(
            &pManager->Frames,
            i );

      if( pFrame != NULL &&
          pFrame->hWnd == hWnd )
         return pFrame;
   }

   return NULL;
}

HB_DOCK_FLOATING_FRAME * hbDockFloatingFindByPanel(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   int i;

   if( pManager == NULL )
      return NULL;

   for( i = 0; i < pManager->Frames.Count; ++i )
   {
      HB_DOCK_FLOATING_FRAME * pFrame;

      pFrame =
         ( HB_DOCK_FLOATING_FRAME * )
         hbDockArrayGet(
            &pManager->Frames,
            i );

      if( pFrame != NULL &&
          pFrame->Panel == pPanel )
         return pFrame;
   }

   return NULL;
}