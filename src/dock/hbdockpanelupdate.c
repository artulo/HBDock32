#include "hbdockpanelupdate.h"

void hbDockPanelBeginUpdate(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   ++pPanel->UpdateCount;
}

void hbDockPanelEndUpdate(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   if( pPanel->UpdateCount > 0 )
      --pPanel->UpdateCount;
}

int hbDockPanelIsUpdating(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->UpdateCount > 0;
}