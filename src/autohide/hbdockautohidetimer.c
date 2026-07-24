#include <windows.h>

#include "hbdockautohidetimer.h"


UINT_PTR hbDockAutoHideStartTimer(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT_PTR nId,
   UINT nElapse )
{
   if( pAutoHide == NULL )
      return 0;

   if( pAutoHide->Panel == NULL )
      return 0;

   if( pAutoHide->Panel->hWnd == NULL )
      return 0;

   return SetTimer(
      pAutoHide->Panel->hWnd,
      nId,
      nElapse,
      NULL );
}


void hbDockAutoHideStopTimer(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT_PTR nId )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   KillTimer(
      pAutoHide->Panel->hWnd,
      nId );
}