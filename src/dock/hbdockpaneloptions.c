#include "hbdockpaneloptions.h"

void hbDockPanelSetOptions(
   HB_DOCK_PANEL * pPanel,
   unsigned long ulOptions )
{
   if( pPanel == NULL )
      return;

   pPanel->Options = ulOptions;
}

unsigned long hbDockPanelGetOptions(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->Options;
}

void hbDockPanelEnableOption(
   HB_DOCK_PANEL * pPanel,
   unsigned long ulOption )
{
   if( pPanel == NULL )
      return;

   pPanel->Options |= ulOption;
}

void hbDockPanelDisableOption(
   HB_DOCK_PANEL * pPanel,
   unsigned long ulOption )
{
   if( pPanel == NULL )
      return;

   pPanel->Options &= ~ulOption;
}

int hbDockPanelHasOption(
   const HB_DOCK_PANEL * pPanel,
   unsigned long ulOption )
{
   if( pPanel == NULL )
      return 0;

   return ( pPanel->Options & ulOption ) != 0;
}