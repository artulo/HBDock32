#include "hbdockautohideget.h"

HB_DOCK_AUTOHIDE_PANE *
hbDockAutoHidePaneGet(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   int nIndex )
{
   if( pManager == NULL )
      return NULL;

   return
      ( HB_DOCK_AUTOHIDE_PANE * )
      hbDockArrayGet(
         &pManager->Panes,
         nIndex );
}