#include <windows.h>

#include "hbdockautohidebuttonvisible.h"

void hbDockAutoHideButtonShow(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   pButton->Visible = TRUE;
}

void hbDockAutoHideButtonHide(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   pButton->Visible = FALSE;
}

int hbDockAutoHideButtonIsVisible(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return pButton->Visible;
}