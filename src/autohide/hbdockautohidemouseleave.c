#include "hbdockautohidemouseleave.h"

void hbDockAutoHideBeginMouseLeave(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->WaitingMouseLeave = TRUE;
}


void hbDockAutoHideEndMouseLeave(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->WaitingMouseLeave = FALSE;
}


int hbDockAutoHideWaitingMouseLeave(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return FALSE;

   return pAutoHide->WaitingMouseLeave;
}