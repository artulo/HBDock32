#include <windows.h>

#include "hbdockautohidetimer.h"

#define HB_AUTOHIDE_TIMER 100

UINT_PTR hbDockAutoHideStartTimer(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT Interval )
{
   return SetTimer(
      pPane->hWnd,
      HB_AUTOHIDE_TIMER,
      Interval,
      NULL );
}

void hbDockAutoHideStopTimer(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   KillTimer(
      pPane->hWnd,
      HB_AUTOHIDE_TIMER );
}