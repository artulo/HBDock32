#include <windows.h>

#include "hbdockpanelfont.h"

void hbDockPanelSetFont(
   HB_DOCK_PANEL * pPanel,
   HFONT hFont )
{
   if( pPanel == NULL )
      return;

   pPanel->hFont = hFont;

   if( pPanel->hWnd != NULL )
      SendMessage(
         pPanel->hWnd,
         WM_SETFONT,
         ( WPARAM ) hFont,
         TRUE );
}

HFONT hbDockPanelGetFont(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return NULL;

   return pPanel->hFont;
}