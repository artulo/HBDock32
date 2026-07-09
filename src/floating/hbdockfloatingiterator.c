#include "hbdockfloatingiterator.h"

void hbDockFloatingIteratorInit(
   HB_DOCK_FLOATING_ITERATOR * pIterator,
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   if( pIterator == NULL )
      return;

   pIterator->pManager = pManager;
   pIterator->Index = 0;
}

HB_DOCK_FLOATING_FRAME * hbDockFloatingIteratorNext(
   HB_DOCK_FLOATING_ITERATOR * pIterator )
{
   if( pIterator == NULL )
      return NULL;

   if( pIterator->pManager == NULL )
      return NULL;

   if( pIterator->Index >=
       pIterator->pManager->Frames.Count )
      return NULL;

   return
      ( HB_DOCK_FLOATING_FRAME * )
      hbDockArrayGet(
         &pIterator->pManager->Frames,
         pIterator->Index++ );
}

void hbDockFloatingIteratorReset(
   HB_DOCK_FLOATING_ITERATOR * pIterator )
{
   if( pIterator == NULL )
      return;

   pIterator->Index = 0;
}