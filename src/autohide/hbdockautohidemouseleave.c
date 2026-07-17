#include "hbdockautohidemouseleave.h"

void hbDockAutoHideBeginMouseLeave(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->WaitingMouseLeave = TRUE;
}

void hbDockAutoHideEndMouseLeave(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->WaitingMouseLeave = FALSE;
}

int hbDockAutoHideWaitingMouseLeave(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return FALSE;

   return pPane->WaitingMouseLeave;
}