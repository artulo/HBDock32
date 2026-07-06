#include "hbdockpanelpadding.h"

void hbDockPanelSetPadding(
   HB_DOCK_PANEL * pPanel,
   int Left,
   int Top,
   int Right,
   int Bottom )
{
   if( pPanel == NULL )
      return;

   pPanel->Padding.left   = Left;
   pPanel->Padding.top    = Top;
   pPanel->Padding.right  = Right;
   pPanel->Padding.bottom = Bottom;
}

void hbDockPanelGetPadding(
   const HB_DOCK_PANEL * pPanel,
   RECT * pPadding )
{
   if( pPanel == NULL || pPadding == NULL )
      return;

   *pPadding = pPanel->Padding;
}