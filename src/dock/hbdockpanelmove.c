#include <windows.h>

#include "hbdockpanelmove.h"

void hbDockPanelMoveWindow(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   if( pPanel->hWnd == NULL )
      return;

   MoveWindow(
      pPanel->hWnd,
      pPanel->Rect.left,
      pPanel->Rect.top,
      pPanel->Rect.right -
         pPanel->Rect.left,
      pPanel->Rect.bottom -
         pPanel->Rect.top,
      TRUE );
}

void hbDockPanelResize(
   HB_DOCK_PANEL * pPanel,
   int Width,
   int Height )
{
   if( pPanel == NULL )
      return;

   pPanel->Rect.right =
      pPanel->Rect.left + Width;

   pPanel->Rect.bottom =
      pPanel->Rect.top + Height;

   hbDockPanelMoveWindow(
      pPanel );
}