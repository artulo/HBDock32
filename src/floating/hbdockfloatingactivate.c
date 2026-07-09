#include <windows.h>

#include "hbdockfloatingactivate.h"

void hbDockFloatingActivate(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      SetActiveWindow(
         pFrame->hWnd );
}

void hbDockFloatingDeactivate(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      SendMessage(
         pFrame->hWnd,
         WM_NCACTIVATE,
         FALSE,
         0 );
}

int hbDockFloatingIsActive(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return 0;

   if( pFrame->hWnd == NULL )
      return 0;

   return GetActiveWindow() ==
          pFrame->hWnd;
}