#include <windows.h>

#include "hbdockfloatinguserdata.h"

void hbDockFloatingSetUserData(
   HB_DOCK_FLOATING_FRAME * pFrame,
   void * pData )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd != NULL )
      SetWindowLong(
         pFrame->hWnd,
         GWL_USERDATA,
         ( LONG ) pData );
}

void * hbDockFloatingGetUserData(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return NULL;

   if( pFrame->hWnd == NULL )
      return NULL;

   return
      ( void * )
      GetWindowLong(
         pFrame->hWnd,
         GWL_USERDATA );
}