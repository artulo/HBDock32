#include "hbdockpanelfloating.h"

void hbDockPanelSetFloating(
   HB_DOCK_PANEL * pPanel,
   int bFloating )
{
   if( pPanel == NULL )
      return;

   pPanel->Floating = bFloating;
}

int hbDockPanelIsFloating(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->Floating;
}