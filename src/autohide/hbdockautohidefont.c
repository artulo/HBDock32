#include <windows.h>

#include "hbdockautohidefont.h"

void hbDockAutoHideSetFont(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HFONT hFont )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SendMessage(
      pAutoHide->Panel->hWnd,
      WM_SETFONT,
      (WPARAM) hFont,
      TRUE );
}

HFONT hbDockAutoHideGetFont(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return NULL;

   if( pAutoHide->Panel == NULL )
      return NULL;

   if( pAutoHide->Panel->hWnd == NULL )
      return NULL;

   return (HFONT)
      SendMessage(
         pAutoHide->Panel->hWnd,
         WM_GETFONT,
         0,
         0 );
}