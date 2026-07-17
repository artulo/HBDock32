#include <windows.h>

#include "hbdockautohidebuttonwindowid.h"

int hbDockAutoHideButtonGetWindowId(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return pButton->WindowId;
}

void hbDockAutoHideButtonSetWindowId(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   int nId )
{
   if( pButton == NULL )
      return;

   pButton->WindowId = nId;
}