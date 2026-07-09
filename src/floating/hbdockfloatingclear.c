#include "hbdockfloatingclear.h"

void hbDockFloatingClear(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   while( pManager->Frames.Count > 0 )
   {
      HB_DOCK_FLOATING_FRAME * pFrame;

      pFrame =
         ( HB_DOCK_FLOATING_FRAME * )
         hbDockArrayGet(
            &pManager->Frames,
            0 );

      if( pFrame != NULL )
         hbDockFloatingFrameDestroy(
            pFrame );

      hbDockArrayRemove(
         &pManager->Frames,
         0 );
   }
}