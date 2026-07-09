#include <windows.h>

#include "hbdockfloatingclient.h"

void hbDockFloatingGetClientRect(
   HB_DOCK_FLOATING_FRAME * pFrame,
   RECT * pRect )
{
   if( pFrame == NULL ||
       pRect == NULL )
      return;

   GetClientRect(
      pFrame->hWnd,
      pRect );
}

void hbDockFloatingClientToScreen(
   HB_DOCK_FLOATING_FRAME * pFrame,
   POINT * pPoint )
{
   if( pFrame == NULL ||
       pPoint == NULL )
      return;

   ClientToScreen(
      pFrame->hWnd,
      pPoint );
}

void hbDockFloatingScreenToClient(
   HB_DOCK_FLOATING_FRAME * pFrame,
   POINT * pPoint )
{
   if( pFrame == NULL ||
       pPoint == NULL )
      return;

   ScreenToClient(
      pFrame->hWnd,
      pPoint );
}