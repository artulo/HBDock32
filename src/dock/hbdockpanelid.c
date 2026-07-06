#include "hbdockpanelid.h"

void hbDockPanelSetId(
   HB_DOCK_PANEL * pPanel,
   unsigned int Id )
{
   if( pPanel == NULL )
      return;

   pPanel->Id = Id;
}

unsigned int hbDockPanelGetId(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->Id;
}