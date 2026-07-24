#include <windows.h>

#include "hbdockautohideenablewindow.h"

BOOL hbDockAutoHideEnableWindow(
   HB_DOCK_AUTOHIDE * pAutoHide,
   BOOL bEnable )
{
   if( pAutoHide == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   return EnableWindow(
      pAutoHide->Panel->hWnd,
      bEnable );
}