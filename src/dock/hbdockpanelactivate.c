#include <windows.h>

#include "hbdockpanelactivate.h"

void hbDockPanelActivate(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   pPanel->Active = 1;

   if( pPanel->hWnd != NULL )
      SetFocus(
         pPanel->hWnd );
}

void hbDockPanelDeactivate(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   pPanel->Active = 0;
}

int hbDockPanelIsActive(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->Active;
}