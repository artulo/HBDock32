#include <windows.h>

#include "hbdockpaneltooltip.h"

void hbDockPanelSetToolTip(
   HB_DOCK_PANEL * pPanel,
   HWND hToolTip )
{
   if( pPanel == NULL )
      return;

   pPanel->hToolTip = hToolTip;
}

HWND hbDockPanelGetToolTip(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return NULL;

   return pPanel->hToolTip;
}