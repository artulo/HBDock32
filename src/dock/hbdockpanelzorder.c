#include <windows.h>

#include "hbdockpanelzorder.h"

void hbDockPanelBringToFront(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   if( pPanel->hWnd == NULL )
      return;

   SetWindowPos(
      pPanel->hWnd,
      HWND_TOP,
      0,
      0,
      0,
      0,
      SWP_NOMOVE |
      SWP_NOSIZE );
}

void hbDockPanelSendToBack(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   if( pPanel->hWnd == NULL )
      return;

   SetWindowPos(
      pPanel->hWnd,
      HWND_BOTTOM,
      0,
      0,
      0,
      0,
      SWP_NOMOVE |
      SWP_NOSIZE );
}