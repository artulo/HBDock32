#include <windows.h>

#include "hbdockautohidefocus.h"

void hbDockAutoHideSetFocus(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SetFocus(
      pAutoHide->Panel->hWnd );
}

int hbDockAutoHideHasFocus(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   if( pAutoHide->Panel == NULL )
      return 0;

   if( pAutoHide->Panel->hWnd == NULL )
      return 0;

   return GetFocus() ==
      pAutoHide->Panel->hWnd;
}