#include <windows.h>

#include "hbdockautohideicon.h"

void hbDockAutoHideSetIcon(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HICON hIcon )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SendMessage(
      pAutoHide->Panel->hWnd,
      WM_SETICON,
      ICON_SMALL,
      ( LPARAM ) hIcon );

   SendMessage(
      pAutoHide->Panel->hWnd,
      WM_SETICON,
      ICON_BIG,
      ( LPARAM ) hIcon );
}


HICON hbDockAutoHideGetIcon(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return NULL;

   if( pAutoHide->Panel == NULL )
      return NULL;

   if( pAutoHide->Panel->hWnd == NULL )
      return NULL;

   return ( HICON )
      SendMessage(
         pAutoHide->Panel->hWnd,
         WM_GETICON,
         ICON_SMALL,
         0 );
}