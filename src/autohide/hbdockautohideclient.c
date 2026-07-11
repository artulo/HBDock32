#include <windows.h>

#include "hbdockautohideclient.h"

void hbDockAutoHideGetClientRect(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   RECT * pRect )
{
   if( pPane == NULL || pRect == NULL )
      return;

   GetClientRect(
      pPane->hWnd,
      pRect );
}

void hbDockAutoHideClientToScreen(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   POINT * pPoint )
{
   if( pPane == NULL || pPoint == NULL )
      return;

   ClientToScreen(
      pPane->hWnd,
      pPoint );
}

void hbDockAutoHideScreenToClient(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   POINT * pPoint )
{
   if( pPane == NULL || pPoint == NULL )
      return;

   ScreenToClient(
      pPane->hWnd,
      pPoint );
}