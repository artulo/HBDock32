#include "hbdockautohidedelay.h"

void hbDockAutoHideSetDelay(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT nDelay )
{
   if( pPane != NULL )
      pPane->Delay = nDelay;
}

UINT hbDockAutoHideGetDelay(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Delay;
}