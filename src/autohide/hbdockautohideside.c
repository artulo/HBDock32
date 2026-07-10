#include "hbdockautohideside.h"

void hbDockAutoHidePaneSetSide(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   DWORD nSide )
{
   if( pPane != NULL )
      pPane->Side = nSide;
}

DWORD hbDockAutoHidePaneGetSide(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return HB_AUTOHIDE_LEFT;

   return pPane->Side;
}