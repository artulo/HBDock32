#include <windows.h>

#include "hbdockpanelcursor.h"

void hbDockPanelSetCursor(
   HB_DOCK_PANEL * pPanel,
   HCURSOR hCursor )
{
   if( pPanel == NULL )
      return;

   pPanel->hCursor = hCursor;
}

HCURSOR hbDockPanelGetCursor(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return NULL;

   return pPanel->hCursor;
}

void hbDockPanelApplyCursor(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   if( pPanel->hCursor != NULL )
      SetCursor(
         pPanel->hCursor );
}