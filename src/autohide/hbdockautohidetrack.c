#include "hbdockautohidetrack.h"

void hbDockAutoHideBeginTrack(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Tracking = 1;
}

void hbDockAutoHideEndTrack(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Tracking = 0;
}

int hbDockAutoHideIsTracking(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Tracking;
}