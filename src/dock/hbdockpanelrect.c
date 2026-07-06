#include "hbdockpanelrect.h"

void hbDockPanelSetRect(
   HB_DOCK_PANEL * pPanel,
   const RECT * pRect )
{
   if( pPanel == NULL || pRect == NULL )
      return;

   pPanel->Rect = *pRect;
}

void hbDockPanelGetRect(
   const HB_DOCK_PANEL * pPanel,
   RECT * pRect )
{
   if( pPanel == NULL || pRect == NULL )
      return;

   *pRect = pPanel->Rect;
}

int hbDockPanelWidth(
   const HB_DOCK_PANEL * pPanel )
{
   return
      pPanel->Rect.right -
      pPanel->Rect.left;
}

int hbDockPanelHeight(
   const HB_DOCK_PANEL * pPanel )
{
   return
      pPanel->Rect.bottom -
      pPanel->Rect.top;
}