#include "hbdockfloatingindexof.h"

int hbDockFloatingIndexOf(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   int i;

   if( pManager == NULL )
      return -1;

   for( i = 0;
        i < pManager->Frames.Count;
        ++i )
   {
      if( pManager->Frames.Items[ i ] ==
          pFrame )
         return i;
   }

   return -1;
}