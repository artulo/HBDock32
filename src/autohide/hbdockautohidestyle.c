#include <windows.h>

#include "hbdockautohidestyle.h"

LONG hbDockAutoHideGetStyle(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   if( pAutoHide->Panel == NULL )
      return 0;

   if( pAutoHide->Panel->hWnd == NULL )
      return 0;

   return GetWindowLong(
      pAutoHide->Panel->hWnd,
      GWL_STYLE );
}


void hbDockAutoHideSetStyle(
   HB_DOCK_AUTOHIDE * pAutoHide,
   LONG lStyle )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SetWindowLong(
      pAutoHide->Panel->hWnd,
      GWL_STYLE,
      lStyle );
}


LONG hbDockAutoHideGetExStyle(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   if( pAutoHide->Panel == NULL )
      return 0;

   if( pAutoHide->Panel->hWnd == NULL )
      return 0;

   return GetWindowLong(
      pAutoHide->Panel->hWnd,
      GWL_EXSTYLE );
}


void hbDockAutoHideSetExStyle(
   HB_DOCK_AUTOHIDE * pAutoHide,
   LONG lStyle )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SetWindowLong(
      pAutoHide->Panel->hWnd,
      GWL_EXSTYLE,
      lStyle );
}