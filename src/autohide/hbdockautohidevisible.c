#include <windows.h>

#include "hbdockautohidevisible.h"

void hbDockAutoHideShowWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   ShowWindow(
      pPane->hWnd,
      SW_SHOW );
}

void hbDockAutoHideHideWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   ShowWindow(
      pPane->hWnd,
      SW_HIDE );
}

BOOL hbDockAutoHideWindowVisible(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return FALSE;

   return IsWindowVisible(
      pPane->hWnd );
}