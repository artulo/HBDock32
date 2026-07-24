#include <windows.h>

#include "hbdockautohideowner.h"

HWND hbDockAutoHideGetOwner(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return NULL;

   if( pAutoHide->Panel == NULL )
      return NULL;

   if( pAutoHide->Panel->hWnd == NULL )
      return NULL;

   return GetWindow(
      pAutoHide->Panel->hWnd,
      GW_OWNER );
}


void hbDockAutoHideSetOwner(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HWND hOwner )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SetWindowLong(
      pAutoHide->Panel->hWnd,
      GWL_HWNDPARENT,
      ( LONG ) hOwner );
}