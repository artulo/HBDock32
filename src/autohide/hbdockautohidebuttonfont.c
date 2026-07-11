#include <windows.h>

#include "hbdockautohidebuttonfont.h"

void hbDockAutoHideButtonSetFont(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   HFONT hFont )
{
   if( pButton == NULL )
      return;

   SendMessage(
      pButton->hWnd,
      WM_SETFONT,
      ( WPARAM ) hFont,
      TRUE );
}

HFONT hbDockAutoHideButtonGetFont(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return NULL;

   return ( HFONT )
      SendMessage(
         pButton->hWnd,
         WM_GETFONT,
         0,
         0 );
}