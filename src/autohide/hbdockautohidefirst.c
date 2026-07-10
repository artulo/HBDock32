#include "hbdockautohidefirst.h"

HB_DOCK_AUTOHIDE_PANE *
hbDockAutoHideFirst(
   HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return NULL;

   if( pManager->Panes.Count == 0 )
      return NULL;

   return
      ( HB_DOCK_AUTOHIDE_PANE * )
      pManager->Panes.Items[ 0 ];
}

HB_DOCK_AUTOHIDE_PANE *
hbDockAutoHideLast(
   HB_DOCK_AUTOHIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return NULL;

   if( pManager->Panes.Count == 0 )
      return NULL;

   return
      ( HB_DOCK_AUTOHIDE_PANE * )
      pManager->Panes.Items[
         pManager->Panes.Count - 1 ];
}