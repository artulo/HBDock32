#include "hbdockpaneldock.h"

void hbDockPanelSetDockSite(
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_SITE Site )
{
   if( pPanel == NULL )
      return;

   pPanel->DockSite = ( int ) Site;
}

HB_DOCK_SITE hbDockPanelGetDockSite(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return HB_DOCKSITE_NONE;

   return ( HB_DOCK_SITE ) pPanel->DockSite;
}