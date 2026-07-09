#include "hbdockfloatingsort.h"

void hbDockFloatingSort(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_FLOATING_COMPARE pCompare )
{
   int i;
   int j;

   if( pManager == NULL )
      return;

   if( pCompare == NULL )
      return;

   for( i = 0; i < pManager->Frames.Count - 1; ++i )
   {
      for( j = i + 1; j < pManager->Frames.Count; ++j )
      {
         if( pCompare(
               ( HB_DOCK_FLOATING_FRAME * )
               pManager->Frames.Items[ i ],
               ( HB_DOCK_FLOATING_FRAME * )
               pManager->Frames.Items[ j ] ) > 0 )
         {
            void * pTemp;

            pTemp =
               pManager->Frames.Items[ i ];

            pManager->Frames.Items[ i ] =
               pManager->Frames.Items[ j ];

            pManager->Frames.Items[ j ] =
               pTemp;
         }
      }
   }
}