#include <windows.h>

#include "hbdockautohidebuttonuserdata.h"

void hbDockAutoHideButtonSetUserData(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   void * pData )
{
   if( pButton == NULL )
      return;

   SetWindowLong(
      pButton->hWnd,
      GWL_USERDATA,
      ( LONG ) pData );
}

void * hbDockAutoHideButtonGetUserData(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return NULL;

   return ( void * )
      GetWindowLong(
         pButton->hWnd,
         GWL_USERDATA );
}