#include <windows.h>

#include "hbdockpanelparent.h"

void hbDockPanelSetParent(
   HB_DOCK_PANEL * pPanel,
   HWND hParent )
{
   if( pPanel == NULL )
      return;

   pPanel->hParent = hParent;

   if( pPanel->hWnd != NULL )
      SetParent(
         pPanel->hWnd,
         hParent );
}

HWND hbDockPanelGetParent(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return NULL;

   return pPanel->hParent;
}