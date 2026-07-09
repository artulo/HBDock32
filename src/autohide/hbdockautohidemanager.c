#include <string.h>

#include "hbdockautohidemanager.h"

void hbDockAutoHideManagerInit(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HWND hOwner )
{
   memset(
      pManager,
      0,
      sizeof(
         HB_DOCK_AUTOHIDE_MANAGER ) );

   pManager->hOwner = hOwner;

   hbDockArrayInit(
      &pManager->Panes );
}

void hbDockAutoHideManagerDestroy(
   HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   hbDockArrayDestroy(
      &pManager->Panes );
}

int hbDockAutoHideManagerAdd(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   void * pPane )
{
   return hbDockArrayAdd(
      &pManager->Panes,
      pPane );
}

int hbDockAutoHideManagerRemove(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   void * pPane )
{
   int i;

   for( i = 0; i < pManager->Panes.Count; ++i )
   {
      if( hbDockArrayGet(
             &pManager->Panes,
             i ) == pPane )
         return hbDockArrayRemove(
            &pManager->Panes,
            i );
   }

   return 0;
}

int hbDockAutoHideManagerCount(
   const HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   return pManager->Panes.Count;
}