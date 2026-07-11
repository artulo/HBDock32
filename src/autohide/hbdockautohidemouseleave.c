#include "hbdockautohidemouseleave.h"

void hbDockAutoHideBeginMouseLeave(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->WaitingMouseLeave = 1;
}

void hbDockAutoHideEndMouseLeave(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->WaitingMouseLeave = 0;
}

int hbDockAutoHideWaitingMouseLeave(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->WaitingMouseLeave;
}