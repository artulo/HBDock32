#include <windows.h>

#include "hbdockfloatingcascade.h"

void hbDockFloatingCascade(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   int i;
   int x;
   int y;

   x = 40;
   y = 40;

   for( i = 0; i < pManager->Frames.Count; ++i )
   {
      HB_DOCK_FLOATING_FRAME * pFrame;

      pFrame =
         ( HB_DOCK_FLOATING_FRAME * )
         hbDockArrayGet(
            &pManager->Frames,
            i );

      if( pFrame == NULL )
         continue;

      if( pFrame->hWnd != NULL )
      {
         SetWindowPos(
            pFrame->hWnd,
            NULL,
            x,
            y,
            0,
            0,
            SWP_NOSIZE |
            SWP_NOZORDER );

         x += 24;
         y += 24;
      }
   }
}