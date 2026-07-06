#include <windows.h>

#include "hbdockpanelicon.h"

void hbDockPanelSetIcon(
   HB_DOCK_PANEL * pPanel,
   HICON hIcon )
{
   if( pPanel == NULL )
      return;

   pPanel->hIcon = hIcon;
}

HICON hbDockPanelGetIcon(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return NULL;

   return pPanel->hIcon;
}

void hbDockPanelApplyIcon(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   if( pPanel->hWnd == NULL )
      return;

   SendMessage(
      pPanel->hWnd,
      WM_SETICON,
      ICON_SMALL,
      ( LPARAM ) pPanel->hIcon );
}