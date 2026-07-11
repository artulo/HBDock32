#include <windows.h>

#include "hbdockautohideregion.h"

void hbDockAutoHideSetRegion(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HRGN hRegion,
   BOOL bRedraw )
{
   if( pPane == NULL )
      return;

   SetWindowRgn(
      pPane->hWnd,
      hRegion,
      bRedraw );
}

void hbDockAutoHideClearRegion(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   SetWindowRgn(
      pPane->hWnd,
      NULL,
      TRUE );
}