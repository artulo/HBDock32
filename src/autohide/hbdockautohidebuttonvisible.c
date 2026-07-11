#include <windows.h>

#include "hbdockautohidebuttonvisible.h"

void hbDockAutoHideButtonShow(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   ShowWindow(
      pButton->hWnd,
      SW_SHOW );
}

void hbDockAutoHideButtonHide(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   ShowWindow(
      pButton->hWnd,
      SW_HIDE );
}

int hbDockAutoHideButtonIsVisible(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return IsWindowVisible(
      pButton->hWnd );
}