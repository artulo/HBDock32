#include "hbdockautohidebuttonfont.h"

void hbDockAutoHideButtonSetFont(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   HFONT hFont )
{
   if( pButton == NULL )
      return;

   pButton->hFont = hFont;
}

HFONT hbDockAutoHideButtonGetFont(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return NULL;

   return pButton->hFont;
}