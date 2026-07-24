#include "hbdockfloatinginsert.h"
 
int hbDockFloatingInsert(
   HB_DOCK_FLOATING_MANAGER * pManager,
   int Index,
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   int i;

   if( pManager == NULL )
      return 0;

   if( Index < 0 )
      Index = 0;

   if( Index > pManager->Frames.Count )
      Index = pManager->Frames.Count;

   if( !hbDockArrayResize(
            &pManager->Frames,
            pManager->Frames.Count + 1 ) )
      return 0;

   for( i = pManager->Frames.Count - 1;
        i > Index;
        --i )
   {
      pManager->Frames.Items[ i ] =
         pManager->Frames.Items[ i - 1 ];
   }

   pManager->Frames.Items[ Index ] = pFrame;

   return 1;
}