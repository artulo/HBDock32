#include <windows.h>

#include "hbdockfloatingenable.h"

void hbDockFloatingEnable(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      EnableWindow(
         pFrame->hWnd,
         TRUE );
}

void hbDockFloatingDisable(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      EnableWindow(
         pFrame->hWnd,
         FALSE );
}

int hbDockFloatingIsEnabled(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return 0;

   if( pFrame->hWnd == NULL )
      return 0;

   return IsWindowEnabled(
      pFrame->hWnd );
}