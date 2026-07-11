#include <windows.h>

#include "hbdockautohidebuttonstyle.h"

LONG hbDockAutoHideButtonGetStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return GetWindowLong(
      pButton->hWnd,
      GWL_STYLE );
}

void hbDockAutoHideButtonSetStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   LONG lStyle )
{
   if( pButton == NULL )
      return;

   SetWindowLong(
      pButton->hWnd,
      GWL_STYLE,
      lStyle );
}

LONG hbDockAutoHideButtonGetExStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return GetWindowLong(
      pButton->hWnd,
      GWL_EXSTYLE );
}

void hbDockAutoHideButtonSetExStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   LONG lStyle )
{
   if( pButton == NULL )
      return;

   SetWindowLong(
      pButton->hWnd,
      GWL_EXSTYLE,
      lStyle );
}