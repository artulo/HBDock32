#include <windows.h>

#include "hbdockfloatingowner.h"

void hbDockFloatingSetOwner(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HWND hOwner )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd == NULL )
      return;

   SetWindowLong(
      pFrame->hWnd,
      GWL_HWNDPARENT,
      ( LONG ) hOwner );
}

HWND hbDockFloatingGetOwner(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return NULL;

   if( pFrame->hWnd == NULL )
      return NULL;

   return ( HWND )
      GetWindowLong(
         pFrame->hWnd,
         GWL_HWNDPARENT );
}