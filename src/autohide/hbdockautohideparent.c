#include <windows.h>

#include "hbdockautohideparent.h"

HWND hbDockAutoHideGetParent(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return NULL;

   if( pAutoHide->Panel == NULL )
      return NULL;

   if( pAutoHide->Panel->hWnd == NULL )
      return NULL;

   return GetParent(
      pAutoHide->Panel->hWnd );
}

void hbDockAutoHideSetParent(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HWND hParent )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SetParent(
      pAutoHide->Panel->hWnd,
      hParent );
}