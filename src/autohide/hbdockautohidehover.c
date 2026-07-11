#include "hbdockautohidehover.h"

void hbDockAutoHideBeginHover(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Hover = 1;
}

void hbDockAutoHideEndHover(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Hover = 0;
}

int hbDockAutoHideIsHover(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Hover;
}