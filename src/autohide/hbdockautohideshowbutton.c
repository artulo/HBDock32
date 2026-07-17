#include "hbdockautohideshowbutton.h"

void hbDockAutoHideShowButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   pButton->Visible = TRUE;
}

void hbDockAutoHideHideButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   pButton->Visible = FALSE;
}