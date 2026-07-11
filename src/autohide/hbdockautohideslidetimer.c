#include <windows.h>

#include "hbdockautohideslidetimer.h"

BOOL hbDockAutoHideStartSlideTimer(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT nInterval )
{
   if( pPane == NULL )
      return FALSE;

   return SetTimer(
      pPane->hWnd,
      100,
      nInterval,
      NULL ) != 0;
}

void hbDockAutoHideStopSlideTimer(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   KillTimer(
      pPane->hWnd,
      100 );
}