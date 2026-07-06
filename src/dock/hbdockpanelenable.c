#include <windows.h>

#include "hbdockpanelenable.h"

void hbDockPanelEnable(
   HB_DOCK_PANEL * pPanel,
   int Enable )
{
   if( pPanel == NULL )
      return;

   pPanel->Enabled = Enable;

   if( pPanel->hWnd != NULL )
      EnableWindow(
         pPanel->hWnd,
         Enable );
}

int hbDockPanelIsEnabled(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->Enabled;
}