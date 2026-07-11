#include <windows.h>

#include "hbdockautohidezorder.h"

void hbDockAutoHideBringToFront(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   SetWindowPos(
      pPane->hWnd,
      HWND_TOP,
      0,
      0,
      0,
      0,
      SWP_NOMOVE |
      SWP_NOSIZE );
}

void hbDockAutoHideSendToBack(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   SetWindowPos(
      pPane->hWnd,
      HWND_BOTTOM,
      0,
      0,
      0,
      0,
      SWP_NOMOVE |
      SWP_NOSIZE );
}