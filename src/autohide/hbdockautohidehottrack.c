#include "hbdockautohidehottrack.h"

void hbDockAutoHideSetHotTrack(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int bEnable )
{
   if( pAutoHide != NULL )
      pAutoHide->HotTrack = bEnable;
}


int hbDockAutoHideGetHotTrack(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return FALSE;

   return pAutoHide->HotTrack;
}