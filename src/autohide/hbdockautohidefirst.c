#include "hbdockautohidefirst.h"

HB_DOCK_AUTOHIDE *
hbDockAutoHideFirst(
   HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return NULL;

   if( pManager->Panes.Count == 0 )
      return NULL;

   return
      ( HB_DOCK_AUTOHIDE * )
      pManager->Panes.Items[ 0 ];
}

HB_DOCK_AUTOHIDE *
hbDockAutoHideLast(
   HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return NULL;

   if( pManager->Panes.Count == 0 )
      return NULL;

   return
      ( HB_DOCK_AUTOHIDE * )
      pManager->Panes.Items[
         pManager->Panes.Count - 1 ];
}