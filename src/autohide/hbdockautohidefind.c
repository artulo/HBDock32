#include "hbdockautohidefind.h"

HB_DOCK_AUTOHIDE *
hbDockAutoHideFindPanel(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   int i;

   if( pManager == NULL )
      return NULL;

   for( i = 0; i < pManager->Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE * pAutoHide;

      pAutoHide =
         ( HB_DOCK_AUTOHIDE * )
         hbDockArrayGet(
            &pManager->Panes,
            i );

      if( pAutoHide != NULL &&
          pAutoHide->Panel == pPanel )
         return pAutoHide;
   }

   return NULL;
}