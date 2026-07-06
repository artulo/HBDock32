#include "hbdockpanelfloatrect.h"

void hbDockPanelSetFloatRect(
   HB_DOCK_PANEL * pPanel,
   const RECT * pRect )
{
   if( pPanel == NULL || pRect == NULL )
      return;

   pPanel->FloatRect = *pRect;
}

void hbDockPanelGetFloatRect(
   const HB_DOCK_PANEL * pPanel,
   RECT * pRect )
{
   if( pPanel == NULL || pRect == NULL )
      return;

   *pRect = pPanel->FloatRect;
}