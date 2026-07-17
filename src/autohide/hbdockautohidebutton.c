#include <windows.h>

#include "hbdockautohidebutton.h"

void hbDockAutoHideButtonInit(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   SetRectEmpty( &pButton->Rect );

   pButton->Panel = NULL;
   pButton->Hot = FALSE;
   pButton->Pressed = FALSE;
   pButton->Checked = FALSE;
   pButton->hFont = NULL;
   pButton->hIcon = NULL;
   pButton->Text[ 0 ] = TEXT( '\0' );
   pButton->pUserData = NULL;
   pButton->Visible = TRUE;
   pButton->WindowId = 0;
   pButton->Enabled = TRUE;
	
}