#include <windows.h>

#include "hbdockfloatingfocus.h"

void hbDockFloatingSetFocus(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      SetFocus(
         pFrame->hWnd );
}

int hbDockFloatingHasFocus(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return 0;

   if( pFrame->hWnd == NULL )
      return 0;

   return GetFocus() ==
          pFrame->hWnd;
}

HWND hbDockFloatingGetFocus(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return NULL;

   return GetFocus();
}