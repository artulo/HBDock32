#include <windows.h>

#include "hbdockautohideenableredraw.h"

void hbDockAutoHideLockRedraw(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SendMessage(
      pAutoHide->Panel->hWnd,
      WM_SETREDRAW,
      FALSE,
      0 );
}

void hbDockAutoHideUnlockRedraw(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SendMessage(
      pAutoHide->Panel->hWnd,
      WM_SETREDRAW,
      TRUE,
      0 );

   InvalidateRect(
      pAutoHide->Panel->hWnd,
      NULL,
      TRUE );

   UpdateWindow(
      pAutoHide->Panel->hWnd );
}