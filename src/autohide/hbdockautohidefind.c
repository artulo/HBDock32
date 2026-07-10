#include "hbdockautohidefind.h"

HB_DOCK_AUTOHIDE_PANE *
hbDockAutoHideFindPanel(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   int i;

   if( pManager == NULL )
      return NULL;

   for( i = 0; i < pManager->Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE_PANE * pPane;

      pPane =
         ( HB_DOCK_AUTOHIDE_PANE * )
         hbDockArrayGet(
            &pManager->Panes,
            i );

      if( pPane != NULL &&
          pPane->Panel == pPanel )
         return pPane;
   }

   return NULL;
}