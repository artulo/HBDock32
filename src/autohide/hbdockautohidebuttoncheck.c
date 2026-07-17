#include <windows.h>

#include "hbdockautohidebuttoncheck.h"

void hbDockAutoHideButtonCheck(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton )
      pButton->Checked = TRUE;
}

void hbDockAutoHideButtonUncheck(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton )
      pButton->Checked = FALSE;
}

int hbDockAutoHideButtonIsChecked(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return FALSE;

   return pButton->Checked;
}