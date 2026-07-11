#include <windows.h>

#include "hbdockautohidefocus.h"

void hbDockAutoHideSetFocus(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   SetFocus(
      pPane->hWnd );
}

int hbDockAutoHideHasFocus(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return GetFocus() ==
      pPane->hWnd;
}