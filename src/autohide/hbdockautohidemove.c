#include <windows.h>

#include "hbdockautohidemove.h"

void hbDockAutoHideMove(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int x,
   int y )
{
   RECT rc;

   if( pPane == NULL )
      return;

   GetWindowRect(
      pPane->hWnd,
      &rc );

   MoveWindow(
      pPane->hWnd,
      x,
      y,
      rc.right - rc.left,
      rc.bottom - rc.top,
      TRUE );
}

void hbDockAutoHideResize(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int cx,
   int cy )
{
   RECT rc;

   if( pPane == NULL )
      return;

   GetWindowRect(
      pPane->hWnd,
      &rc );

   MoveWindow(
      pPane->hWnd,
      rc.left,
      rc.top,
      cx,
      cy,
      TRUE );
}