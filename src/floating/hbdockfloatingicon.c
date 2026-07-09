#include <windows.h>

#include "hbdockfloatingicon.h"

void hbDockFloatingSetIcon(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HICON hIcon )
{
   if( pFrame == NULL )
      return;

   SendMessage(
      pFrame->hWnd,
      WM_SETICON,
      ICON_SMALL,
      ( LPARAM ) hIcon );

   SendMessage(
      pFrame->hWnd,
      WM_SETICON,
      ICON_BIG,
      ( LPARAM ) hIcon );
}

HICON hbDockFloatingGetIcon(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return NULL;

   return ( HICON )
      SendMessage(
         pFrame->hWnd,
         WM_GETICON,
         ICON_SMALL,
         0 );
}