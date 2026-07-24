#include <windows.h>

#include "hbdockautohidewindowid.h"


int hbDockAutoHideGetWindowId(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   if( pAutoHide->Panel == NULL )
      return 0;

   if( pAutoHide->Panel->hWnd == NULL )
      return 0;

   return GetWindowLong(
      pAutoHide->Panel->hWnd,
      GWL_ID );
}


void hbDockAutoHideSetWindowId(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nId )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SetWindowLong(
      pAutoHide->Panel->hWnd,
      GWL_ID,
      ( LONG ) nId );
}