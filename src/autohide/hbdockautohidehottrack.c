#include "hbdockautohidehottrack.h"

void hbDockAutoHideSetHotTrack(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int bEnable )
{
   if( pPane != NULL )
      pPane->HotTrack = bEnable;
}

int hbDockAutoHideGetHotTrack(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return FALSE;

   return pPane->HotTrack;
}
