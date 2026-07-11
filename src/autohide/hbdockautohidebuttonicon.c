#include <windows.h>

#include "hbdockautohidebuttonicon.h"

void hbDockAutoHideButtonSetIcon(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   HICON hIcon )
{
   if( pButton == NULL )
      return;

   SendMessage(
      pButton->hWnd,
      BM_SETIMAGE,
      IMAGE_ICON,
      ( LPARAM ) hIcon );
}

HICON hbDockAutoHideButtonGetIcon(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return NULL;

   return ( HICON )
      SendMessage(
         pButton->hWnd,
         BM_GETIMAGE,
         IMAGE_ICON,
         0 );
}