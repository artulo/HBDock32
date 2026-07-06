#include "hbdockpanelwindow.h"

void hbDockPanelAttachWindow(
   HB_DOCK_PANEL * pPanel,
   HWND hWnd )
{
   if( pPanel == NULL )
      return;

   pPanel->hWnd = hWnd;
}

HWND hbDockPanelDetachWindow(
   HB_DOCK_PANEL * pPanel )
{
   HWND hWnd;

   if( pPanel == NULL )
      return NULL;

   hWnd = pPanel->hWnd;
   pPanel->hWnd = NULL;

   return hWnd;
}