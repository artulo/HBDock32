#include <windows.h>

#include "hbdockfloatingtimer.h"

UINT_PTR hbDockFloatingStartTimer(
   HB_DOCK_FLOATING_FRAME * pFrame,
   UINT_PTR nId,
   UINT nInterval )
{
   if( pFrame == NULL )
      return 0;

   return SetTimer(
      pFrame->hWnd,
      nId,
      nInterval,
      NULL );
}

void hbDockFloatingStopTimer(
   HB_DOCK_FLOATING_FRAME * pFrame,
   UINT_PTR nId )
{
   if( pFrame == NULL )
      return;

   KillTimer(
      pFrame->hWnd,
      nId );
}