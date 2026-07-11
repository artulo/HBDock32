#include <windows.h>

#include "hbdockautohidetimer.h"

UINT_PTR hbDockAutoHideStartTimer(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT_PTR nId,
   UINT nElapse )
{
   if( pPane == NULL )
      return 0;

   return SetTimer(
      pPane->hWnd,
      nId,
      nElapse,
      NULL );
}

void hbDockAutoHideStopTimer(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT_PTR nId )
{
   if( pPane == NULL )
      return;

   KillTimer(
      pPane->hWnd,
      nId );
}