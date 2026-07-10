#include "hbdockautohideenum.h"

void hbDockAutoHideEnum(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HB_DOCK_AUTOHIDE_ENUMPROC pProc,
   void * Cargo )
{
   int i;

   if( pManager == NULL )
      return;

   if( pProc == NULL )
      return;

   for( i = 0; i < pManager->Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE_PANE * pPane;

      pPane =
         ( HB_DOCK_AUTOHIDE_PANE * )
         hbDockArrayGet(
            &pManager->Panes,
            i );

      if( pPane != NULL )
      {
         if( !pProc(
                 pPane,
                 Cargo ) )
            break;
      }
   }
}