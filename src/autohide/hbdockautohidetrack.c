#include "hbdockautohidetrack.h"

void hbDockAutoHideBeginTrack(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Tracking = 1;
}


void hbDockAutoHideEndTrack(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Tracking = 0;
}


int hbDockAutoHideIsTracking(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->Tracking;
}