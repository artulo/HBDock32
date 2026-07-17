#include "hbdockautohideselected.h"

void hbDockAutoHideSelect(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Selected = TRUE;
}

void hbDockAutoHideUnselect(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Selected = FALSE;
}

int hbDockAutoHideIsSelected(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return FALSE;

   return pPane->Selected;
}