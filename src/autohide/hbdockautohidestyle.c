#include <windows.h>

#include "hbdockautohidestyle.h"

LONG hbDockAutoHideGetStyle(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return GetWindowLong(
      pPane->hWnd,
      GWL_STYLE );
}

void hbDockAutoHideSetStyle(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   LONG lStyle )
{
   if( pPane == NULL )
      return;

   SetWindowLong(
      pPane->hWnd,
      GWL_STYLE,
      lStyle );
}

LONG hbDockAutoHideGetExStyle(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return GetWindowLong(
      pPane->hWnd,
      GWL_EXSTYLE );
}

void hbDockAutoHideSetExStyle(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   LONG lStyle )
{
   if( pPane == NULL )
      return;

   SetWindowLong(
      pPane->hWnd,
      GWL_EXSTYLE,
      lStyle );
}