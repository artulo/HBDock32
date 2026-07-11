#include "hbdockautohideselected.h"

void hbDockAutoHideSelect(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Selected = 1;
}

void hbDockAutoHideUnselect(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Selected = 0;
}

int hbDockAutoHideIsSelected(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Selected;
}