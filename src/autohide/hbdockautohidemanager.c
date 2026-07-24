#include <string.h>

#include "hbdockautohidemanager.h"
#include "hbdockarray.h"

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

   hbDockArrayRelease(
      &pManager->Panes );
}


int hbDockAutoHideManagerAdd(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   void * pPane )
{
   if( pManager == NULL )
      return 0;

   return hbDockArrayAdd(
      &pManager->Panes,
      pPane );
}


int hbDockAutoHideManagerRemove(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   void * pPane )
{
   int i;

   if( pManager == NULL )
      return 0;

   for( i = 0; i < pManager->Panes.Count; ++i )
   {
      if( hbDockArrayGet(
             &pManager->Panes,
             i ) == pPane )
      {
         return hbDockArrayRemove(
            &pManager->Panes,
            i );
      }
   }

   return 0;
}


int hbDockAutoHideManagerCount(
   const HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return 0;

   return pManager->Panes.Count;
}