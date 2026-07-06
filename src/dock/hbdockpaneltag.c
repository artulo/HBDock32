#include "hbdockpaneltag.h"

void hbDockPanelSetTag(
   HB_DOCK_PANEL * pPanel,
   long lTag )
{
   if( pPanel == NULL )
      return;

   pPanel->Tag = lTag;
}

long hbDockPanelGetTag(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->Tag;
}