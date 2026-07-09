#include <windows.h>

#include "hbdockfloatingregion.h"

void hbDockFloatingSetRegion(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HRGN hRegion,
   int bRedraw )
{
   if( pFrame == NULL )
      return;

   SetWindowRgn(
      pFrame->hWnd,
      hRegion,
      bRedraw );
}

void hbDockFloatingClearRegion(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   SetWindowRgn(
      pFrame->hWnd,
      NULL,
      TRUE );
}