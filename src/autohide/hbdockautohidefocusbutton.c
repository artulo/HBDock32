#include <windows.h>

#include "hbdockautohidefocusbutton.h"

void hbDockAutoHideFocusButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   SetFocus(
      pButton->hWnd );
}

int hbDockAutoHideButtonHasFocus(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return GetFocus() ==
      pButton->hWnd;
}