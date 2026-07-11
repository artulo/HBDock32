#include <windows.h>

#include "hbdockautohideredrawwindow.h"

BOOL hbDockAutoHideRedrawWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT uFlags )
{
   if( pPane == NULL )
      return FALSE;

   return RedrawWindow(
      pPane->hWnd,
      NULL,
      NULL,
      uFlags );
}