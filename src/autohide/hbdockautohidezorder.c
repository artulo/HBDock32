#include <windows.h>

#include "hbdockautohidezorder.h"


void hbDockAutoHideBringToFront(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;


   SetWindowPos(
      pAutoHide->Panel->hWnd,
      HWND_TOP,
      0,
      0,
      0,
      0,
      SWP_NOMOVE |
      SWP_NOSIZE );
}


void hbDockAutoHideSendToBack(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;


   SetWindowPos(
      pAutoHide->Panel->hWnd,
      HWND_BOTTOM,
      0,
      0,
      0,
      0,
      SWP_NOMOVE |
      SWP_NOSIZE );
}