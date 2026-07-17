#include "hbdockautohidebuttonicon.h"

void hbDockAutoHideButtonSetIcon(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   HICON hIcon )
{
   if( pButton == NULL )
      return;

   pButton->hIcon = hIcon;
}

HICON hbDockAutoHideButtonGetIcon(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return NULL;

   return pButton->hIcon;
}