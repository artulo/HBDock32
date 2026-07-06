#include <windows.h>

#include "hbdockpanelborder.h"

void hbDockPanelSetBorder(
   HB_DOCK_PANEL * pPanel,
   int nBorder )
{
   if( pPanel == NULL )
      return;

   pPanel->Border = nBorder;
}

int hbDockPanelGetBorder(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->Border;
}

RECT hbDockPanelGetClientRect(
   const HB_DOCK_PANEL * pPanel )
{
   RECT rc;

   rc = pPanel->Rect;

   InflateRect(
      &rc,
      -pPanel->Border,
      -pPanel->Border );

   return rc;
}