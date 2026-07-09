#include "hbdockfloatingreverse.h"

void hbDockFloatingReverse(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   int i;
   int j;

   if( pManager == NULL )
      return;

   i = 0;
   j = pManager->Frames.Count - 1;

   while( i < j )
   {
      void * pTemp;

      pTemp =
         pManager->Frames.Items[ i ];

      pManager->Frames.Items[ i ] =
         pManager->Frames.Items[ j ];

      pManager->Frames.Items[ j ] =
         pTemp;

      ++i;
      --j;
   }
}