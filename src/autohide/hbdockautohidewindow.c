#include <windows.h>

#include "hbdockautohidewindow.h"

HWND hbDockAutoHideGetWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return NULL;

   return pPane->hWnd;
}

BOOL hbDockAutoHideIsWindow(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return FALSE;

   return IsWindow(
      pPane->hWnd );
}