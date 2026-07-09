#include <windows.h>

#include "hbdockfloatingcenter.h"

void hbDockFloatingCenter(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HWND hParent )
{
   RECT rcParent;
   RECT rcWindow;
   int x;
   int y;

   if( pFrame == NULL )
      return;

   if( pFrame->hWnd == NULL )
      return;

   GetWindowRect(
      hParent,
      &rcParent );

   GetWindowRect(
      pFrame->hWnd,
      &rcWindow );

   x =
      rcParent.left +
      ( ( rcParent.right - rcParent.left ) -
        ( rcWindow.right - rcWindow.left ) ) / 2;

   y =
      rcParent.top +
      ( ( rcParent.bottom - rcParent.top ) -
        ( rcWindow.bottom - rcWindow.top ) ) / 2;

   SetWindowPos(
      pFrame->hWnd,
      NULL,
      x,
      y,
      0,
      0,
      SWP_NOSIZE |
      SWP_NOZORDER );
}