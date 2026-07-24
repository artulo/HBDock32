#include <windows.h>

#include "hbdockautohidemove.h"

void hbDockAutoHideMove(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int x,
   int y )
{
   RECT rc;

   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   GetWindowRect(
      pAutoHide->Panel->hWnd,
      &rc );

   MoveWindow(
      pAutoHide->Panel->hWnd,
      x,
      y,
      rc.right - rc.left,
      rc.bottom - rc.top,
      TRUE );
}


void hbDockAutoHideResize(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int cx,
   int cy )
{
   RECT rc;

   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   GetWindowRect(
      pAutoHide->Panel->hWnd,
      &rc );

   MoveWindow(
      pAutoHide->Panel->hWnd,
      rc.left,
      rc.top,
      cx,
      cy,
      TRUE );
}