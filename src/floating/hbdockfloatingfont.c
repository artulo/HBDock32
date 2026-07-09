#include <windows.h>

#include "hbdockfloatingfont.h"

void hbDockFloatingSetFont(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HFONT hFont )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      SendMessage(
         pFrame->hWnd,
         WM_SETFONT,
         ( WPARAM ) hFont,
         TRUE );
}

HFONT hbDockFloatingGetFont(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return NULL;

   if( pFrame->hWnd == NULL )
      return NULL;

   return
      ( HFONT )
      SendMessage(
         pFrame->hWnd,
         WM_GETFONT,
         0,
         0 );
}