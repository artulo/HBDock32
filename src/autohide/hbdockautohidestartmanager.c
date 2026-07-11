#include <windows.h>

#include "hbdockautohidestartmanager.h"
#include "hbdockautohidetimerproc.h"

int hbDockAutoHideAnimationStart(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager,
   HWND hWnd )
{
   if( pManager == NULL )
      return 0;

   pManager->TimerId =
      SetTimer(
         hWnd,
         1000,
         pManager->Interval,
         hbDockAutoHideTimerProc );

   return pManager->TimerId != 0;
}

void hbDockAutoHideAnimationStop(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager,
   HWND hWnd )
{
   if( pManager == NULL )
      return;

   if( pManager->TimerId )
   {
      KillTimer(
         hWnd,
         pManager->TimerId );

      pManager->TimerId = 0;
   }
}