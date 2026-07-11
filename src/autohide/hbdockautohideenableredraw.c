#include <windows.h>

#include "hbdockautohideenableredraw.h"

void hbDockAutoHideLockRedraw(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   SendMessage(
      pPane->hWnd,
      WM_SETREDRAW,
      FALSE,
      0 );
}

void hbDockAutoHideUnlockRedraw(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   SendMessage(
      pPane->hWnd,
      WM_SETREDRAW,
      TRUE,
      0 );

   InvalidateRect(
      pPane->hWnd,
      NULL,
      TRUE );

   UpdateWindow(
      pPane->hWnd );
}