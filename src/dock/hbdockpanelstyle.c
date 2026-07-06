#include <windows.h>

#include "hbdockpanelstyle.h"

void hbDockPanelSetStyle(
   HB_DOCK_PANEL * pPanel,
   DWORD dwStyle )
{
   if( pPanel == NULL )
      return;

   pPanel->Style = dwStyle;

   if( pPanel->hWnd != NULL )
      SetWindowLong(
         pPanel->hWnd,
         GWL_STYLE,
         ( LONG ) dwStyle );
}

void hbDockPanelSetExStyle(
   HB_DOCK_PANEL * pPanel,
   DWORD dwExStyle )
{
   if( pPanel == NULL )
      return;

   pPanel->ExStyle = dwExStyle;

   if( pPanel->hWnd != NULL )
      SetWindowLong(
         pPanel->hWnd,
         GWL_EXSTYLE,
         ( LONG ) dwExStyle );
}

DWORD hbDockPanelGetStyle(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->Style;
}

DWORD hbDockPanelGetExStyle(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->ExStyle;
}