#include "hbdockautohidehover.h"

void hbDockAutoHideBeginHover(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Hover = TRUE;
}

void hbDockAutoHideEndHover(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Hover = FALSE;
}

int hbDockAutoHideIsHover(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return FALSE;

   return pPane->Hover;
}