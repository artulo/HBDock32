#include <windows.h>

#include "hbdockautohideenablewindow.h"

BOOL hbDockAutoHideEnableWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   BOOL bEnable )
{
   if( pPane == NULL )
      return FALSE;

   return EnableWindow(
      pPane->hWnd,
      bEnable );
}