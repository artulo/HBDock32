#include "hbdockpanelmodified.h"

void hbDockPanelSetModified(
   HB_DOCK_PANEL * pPanel,
   int bModified )
{
   if( pPanel == NULL )
      return;

   pPanel->Modified = bModified;
}

int hbDockPanelIsModified(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->Modified;
}

void hbDockPanelClearModified(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   pPanel->Modified = 0;
}