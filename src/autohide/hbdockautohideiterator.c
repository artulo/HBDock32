#include "hbdockautohideiterator.h"

void hbDockAutoHideIteratorInit(
   HB_DOCK_AUTOHIDE_ITERATOR * pIterator,
   HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   pIterator->pManager = pManager;
   pIterator->Index = 0;
}

HB_DOCK_AUTOHIDE_PANE *
hbDockAutoHideIteratorNext(
   HB_DOCK_AUTOHIDE_ITERATOR * pIterator )
{
   if( pIterator == NULL )
      return NULL;

   if( pIterator->pManager == NULL )
      return NULL;

   if( pIterator->Index >=
       pIterator->pManager->Panes.Count )
      return NULL;

   return
      ( HB_DOCK_AUTOHIDE_PANE * )
      hbDockArrayGet(
         &pIterator->pManager->Panes,
         pIterator->Index++ );
}