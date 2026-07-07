#include "hbdockfloatingmanager.h"

void hbDockFloatingManagerInit(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   hbDockArrayInit(
      &pManager->Frames );
}

void hbDockFloatingManagerDestroy(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   hbDockArrayRelease(
      &pManager->Frames );
}

int hbDockFloatingManagerAdd(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   return hbDockArrayAdd(
      &pManager->Frames,
      pFrame );
}

int hbDockFloatingManagerRemove(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   int i;

   for( i = 0;
        i < pManager->Frames.Count;
        i++ )
   {
      if( hbDockArrayGet(
             &pManager->Frames,
             i ) == pFrame )
         return hbDockArrayRemove(
            &pManager->Frames,
            i );
   }

   return 0;
}