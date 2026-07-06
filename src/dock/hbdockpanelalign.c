#include "hbdockpanelalign.h"

void hbDockPanelSetAlign(
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_ALIGN Align )
{
   if( pPanel == NULL )
      return;

   pPanel->Align = ( int ) Align;
}

HB_DOCK_ALIGN hbDockPanelGetAlign(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return HB_DOCK_ALIGN_NONE;

   return ( HB_DOCK_ALIGN ) pPanel->Align;
}