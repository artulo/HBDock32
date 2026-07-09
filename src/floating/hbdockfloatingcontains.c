#include "hbdockfloatingcontains.h"

int hbDockFloatingContains(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   int i;

   if( pManager == NULL )
      return 0;

   for( i = 0; i < pManager->Frames.Count; ++i )
   {
      if( hbDockArrayGet(
             &pManager->Frames,
             i ) == pFrame )
         return 1;
   }

   return 0;
}