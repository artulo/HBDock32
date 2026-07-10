#include "hbdockautohidepanevisible.h"

void hbDockAutoHidePaneSetVisible(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int bVisible )
{
   if( pPane != NULL )
      pPane->Visible = bVisible;
}

int hbDockAutoHidePaneIsVisible(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Visible;
}