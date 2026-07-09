#include "hbdockfloatingenumerate.h"

void hbDockFloatingEnum(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_FLOATING_ENUMPROC pProc,
   void * Cargo )
{
   int i;

   if( pManager == NULL ||
       pProc == NULL )
      return;

   for( i = 0; i < pManager->Frames.Count; ++i )
   {
      HB_DOCK_FLOATING_FRAME * pFrame;

      pFrame =
         ( HB_DOCK_FLOATING_FRAME * )
         hbDockArrayGet(
            &pManager->Frames,
            i );

      if( pFrame != NULL )
      {
         if( !pProc(
               pFrame,
               Cargo ) )
            break;
      }
   }
}