#include "hbdockautohideexpand.h"

void hbDockAutoHideExpand(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Expanded = 1;
}

void hbDockAutoHideCollapse(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Expanded = 0;
}

int hbDockAutoHideIsExpanded(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Expanded;
}