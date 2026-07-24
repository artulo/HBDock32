#include <windows.h>

#include "hbdockautohideregion.h"

void hbDockAutoHideSetRegion(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HRGN hRegion,
   BOOL bRedraw )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SetWindowRgn(
      pAutoHide->Panel->hWnd,
      hRegion,
      bRedraw );
}

void hbDockAutoHideClearRegion(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SetWindowRgn(
      pAutoHide->Panel->hWnd,
      NULL,
      TRUE );
}