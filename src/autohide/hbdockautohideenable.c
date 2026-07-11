#include <windows.h>

#include "hbdockautohideenable.h"

void hbDockAutoHideEnable(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   EnableWindow(
      pPane->hWnd,
      TRUE );
}

void hbDockAutoHideDisable(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   EnableWindow(
      pPane->hWnd,
      FALSE );
}

int hbDockAutoHideIsEnabled(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return IsWindowEnabled(
      pPane->hWnd );
}