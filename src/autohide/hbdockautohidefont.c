#include <windows.h>

#include "hbdockautohidefont.h"

void hbDockAutoHideSetFont(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HFONT hFont )
{
   if( pPane == NULL )
      return;

   SendMessage(
      pPane->hWnd,
      WM_SETFONT,
      ( WPARAM ) hFont,
      TRUE );
}

HFONT hbDockAutoHideGetFont(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return NULL;

   return ( HFONT )
      SendMessage(
         pPane->hWnd,
         WM_GETFONT,
         0,
         0 );
}