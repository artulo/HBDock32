#include <windows.h>

#include "hbdockautohideplacement.h"

BOOL hbDockAutoHideGetPlacement(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   WINDOWPLACEMENT * pPlacement )
{
   if( pPane == NULL || pPlacement == NULL )
      return FALSE;

   pPlacement->length =
      sizeof( WINDOWPLACEMENT );

   return GetWindowPlacement(
      pPane->hWnd,
      pPlacement );
}

BOOL hbDockAutoHideSetPlacement(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   const WINDOWPLACEMENT * pPlacement )
{
   if( pPane == NULL || pPlacement == NULL )
      return FALSE;

   return SetWindowPlacement(
      pPane->hWnd,
      pPlacement );
}