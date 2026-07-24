#include <windows.h>

#include "hbdockautohideclient.h"


void hbDockAutoHideGetClientRect(
   HB_DOCK_AUTOHIDE * pAutoHide,
   RECT * pRect )
{
   if( pAutoHide == NULL || pRect == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   GetClientRect(
      pAutoHide->Panel->hWnd,
      pRect );
}


void hbDockAutoHideClientToScreen(
   HB_DOCK_AUTOHIDE * pAutoHide,
   POINT * pPoint )
{
   if( pAutoHide == NULL || pPoint == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   ClientToScreen(
      pAutoHide->Panel->hWnd,
      pPoint );
}


void hbDockAutoHideScreenToClient(
   HB_DOCK_AUTOHIDE * pAutoHide,
   POINT * pPoint )
{
   if( pAutoHide == NULL || pPoint == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   ScreenToClient(
      pAutoHide->Panel->hWnd,
      pPoint );
}