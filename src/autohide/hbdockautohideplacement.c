#include <windows.h>

#include "hbdockautohideplacement.h"

BOOL hbDockAutoHideGetPlacement(
   HB_DOCK_AUTOHIDE * pAutoHide,
   WINDOWPLACEMENT * pPlacement )
{
   if( pAutoHide == NULL || pPlacement == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   pPlacement->length =
      sizeof( WINDOWPLACEMENT );

   return GetWindowPlacement(
      pAutoHide->Panel->hWnd,
      pPlacement );
}


BOOL hbDockAutoHideSetPlacement(
   HB_DOCK_AUTOHIDE * pAutoHide,
   const WINDOWPLACEMENT * pPlacement )
{
   if( pAutoHide == NULL || pPlacement == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   return SetWindowPlacement(
      pAutoHide->Panel->hWnd,
      pPlacement );
}