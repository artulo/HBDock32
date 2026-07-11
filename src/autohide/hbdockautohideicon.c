#include <windows.h>

#include "hbdockautohideicon.h"

void hbDockAutoHideSetIcon(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HICON hIcon )
{
   if( pPane == NULL )
      return;

   SendMessage(
      pPane->hWnd,
      WM_SETICON,
      ICON_SMALL,
      ( LPARAM ) hIcon );

   SendMessage(
      pPane->hWnd,
      WM_SETICON,
      ICON_BIG,
      ( LPARAM ) hIcon );
}

HICON hbDockAutoHideGetIcon(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return NULL;

   return ( HICON )
      SendMessage(
         pPane->hWnd,
         WM_GETICON,
         ICON_SMALL,
         0 );
}