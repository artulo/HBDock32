#include <windows.h>

#include "hbdockautohideslidetimer.h"

BOOL hbDockAutoHideStartSlideTimer(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT nInterval )
{
   if( pAutoHide == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   return SetTimer(
      pAutoHide->Panel->hWnd,
      100,
      nInterval,
      NULL ) != 0;
}


void hbDockAutoHideStopSlideTimer(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   KillTimer(
      pAutoHide->Panel->hWnd,
      100 );
}