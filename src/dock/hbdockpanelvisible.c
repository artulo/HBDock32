#include <windows.h>

#include "hbdockpanelvisible.h"

void hbDockPanelShow(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   pPanel->Visible = 1;

   if( pPanel->hWnd != NULL )
      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );
}

void hbDockPanelHide(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   pPanel->Visible = 0;

   if( pPanel->hWnd != NULL )
      ShowWindow(
         pPanel->hWnd,
         SW_HIDE );
}

int hbDockPanelIsVisible(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   return pPanel->Visible;
}