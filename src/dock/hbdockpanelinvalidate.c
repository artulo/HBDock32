#include <windows.h>

#include "hbdockpanelinvalidate.h"

void hbDockPanelInvalidate(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   if( pPanel->hWnd == NULL )
      return;

   InvalidateRect(
      pPanel->hWnd,
      NULL,
      TRUE );
}

void hbDockPanelUpdate(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   if( pPanel->hWnd == NULL )
      return;

   UpdateWindow(
      pPanel->hWnd );
}