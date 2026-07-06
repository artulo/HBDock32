#include "hbdockpanelmargin.h"

void hbDockPanelSetMargin(
   HB_DOCK_PANEL * pPanel,
   int Left,
   int Top,
   int Right,
   int Bottom )
{
   if( pPanel == NULL )
      return;

   pPanel->Margin.left   = Left;
   pPanel->Margin.top    = Top;
   pPanel->Margin.right  = Right;
   pPanel->Margin.bottom = Bottom;
}

void hbDockPanelGetMargin(
   const HB_DOCK_PANEL * pPanel,
   RECT * pMargin )
{
   if( pPanel == NULL || pMargin == NULL )
      return;

   *pMargin = pPanel->Margin;
}