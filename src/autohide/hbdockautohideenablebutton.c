#include <windows.h>

#include "hbdockautohideenablebutton.h"

void hbDockAutoHideEnableButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   EnableWindow(
      pButton->hWnd,
      TRUE );
}

void hbDockAutoHideDisableButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   EnableWindow(
      pButton->hWnd,
      FALSE );
}

int hbDockAutoHideButtonEnabled(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return IsWindowEnabled(
      pButton->hWnd );
}