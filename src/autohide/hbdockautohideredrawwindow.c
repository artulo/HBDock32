#include <windows.h>

#include "hbdockautohideredrawwindow.h"

BOOL hbDockAutoHideRedrawWindow(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT uFlags )
{
   if( pAutoHide == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   return RedrawWindow(
      pAutoHide->Panel->hWnd,
      NULL,
      NULL,
      uFlags );
}