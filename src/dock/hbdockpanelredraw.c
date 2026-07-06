#include <windows.h>

#include "hbdockpanelredraw.h"

void hbDockPanelLockRedraw(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   if( pPanel->hWnd == NULL )
      return;

   SendMessage(
      pPanel->hWnd,
      WM_SETREDRAW,
      FALSE,
      0 );
}

void hbDockPanelUnlockRedraw(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   if( pPanel->hWnd == NULL )
      return;

   SendMessage(
      pPanel->hWnd,
      WM_SETREDRAW,
      TRUE,
      0 );

   RedrawWindow(
      pPanel->hWnd,
      NULL,
      NULL,
      RDW_INVALIDATE |
      RDW_ERASE |
      RDW_FRAME |
      RDW_ALLCHILDREN );
}