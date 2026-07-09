#include <windows.h>

#include "hbdockfloatingtile.h"

void hbDockFloatingTileHorizontal(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   HWND hWnd[256];
   UINT n;
   int i;

   n = 0;

   for( i = 0; i < pManager->Frames.Count && n < 256; ++i )
   {
      HB_DOCK_FLOATING_FRAME * pFrame;

      pFrame =
         ( HB_DOCK_FLOATING_FRAME * )
         hbDockArrayGet(
            &pManager->Frames,
            i );

      if( pFrame != NULL &&
          pFrame->hWnd != NULL )
         hWnd[n++] = pFrame->hWnd;
   }

   if( n > 0 )
      TileWindows(
         NULL,
         MDITILE_HORIZONTAL,
         NULL,
         n,
         hWnd );
}

void hbDockFloatingTileVertical(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   HWND hWnd[256];
   UINT n;
   int i;

   n = 0;

   for( i = 0; i < pManager->Frames.Count && n < 256; ++i )
   {
      HB_DOCK_FLOATING_FRAME * pFrame;

      pFrame =
         ( HB_DOCK_FLOATING_FRAME * )
         hbDockArrayGet(
            &pManager->Frames,
            i );

      if( pFrame != NULL &&
          pFrame->hWnd != NULL )
         hWnd[n++] = pFrame->hWnd;
   }

   if( n > 0 )
      TileWindows(
         NULL,
         MDITILE_VERTICAL,
         NULL,
         n,
         hWnd );
}