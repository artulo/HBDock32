#include "hbdockpanelcolor.h"

void hbDockPanelSetBkColor(
   HB_DOCK_PANEL * pPanel,
   COLORREF Color )
{
   if( pPanel == NULL )
      return;

   pPanel->BkColor = Color;
}

void hbDockPanelSetTextColor(
   HB_DOCK_PANEL * pPanel,
   COLORREF Color )
{
   if( pPanel == NULL )
      return;

   pPanel->TextColor = Color;
}

COLORREF hbDockPanelGetBkColor(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return RGB(255,255,255);

   return pPanel->BkColor;
}

COLORREF hbDockPanelGetTextColor(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return RGB(0,0,0);

   return pPanel->TextColor;
}