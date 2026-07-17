#include <windows.h>

#include "hbdockfloatingstate.h"

void hbDockFloatingSetState(
   HB_DOCK_FLOATING_FRAME * pFrame,
   int nState )
{
   if( pFrame == NULL )
      return;

   switch( nState )
   {
      case HB_FLOAT_STATE_HIDDEN:
         ShowWindow( pFrame->hWnd, SW_HIDE );
         break;

      case HB_FLOAT_STATE_MINIMIZED:
         ShowWindow( pFrame->hWnd, SW_MINIMIZE );
         break;

      case HB_FLOAT_STATE_MAXIMIZED:
         ShowWindow( pFrame->hWnd, SW_MAXIMIZE );
         break;

      default:
         ShowWindow( pFrame->hWnd, SW_RESTORE );
         break;
   }
}

int hbDockFloatingGetState(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   WINDOWPLACEMENT wp;

   if( pFrame == NULL )
      return HB_FLOAT_STATE_HIDDEN;

   wp.length = sizeof( WINDOWPLACEMENT );

   if( !GetWindowPlacement(
         pFrame->hWnd,
         &wp ) )
      return HB_FLOAT_STATE_HIDDEN;

    switch( wp.showCmd )
	{
	   case SW_MINIMIZE:
		  return HB_FLOAT_STATE_MINIMIZED;

	   case SW_MAXIMIZE:
		  return HB_FLOAT_STATE_MAXIMIZED;
	}

   if( IsWindowVisible( pFrame->hWnd ) )
      return HB_FLOAT_STATE_NORMAL;

   return HB_FLOAT_STATE_HIDDEN;
}