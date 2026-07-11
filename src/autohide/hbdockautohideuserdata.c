#include <windows.h>

#include "hbdockautohideuserdata.h"

void hbDockAutoHideSetUserData(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   void * pData )
{
   if( pPane == NULL )
      return;

   SetWindowLong(
      pPane->hWnd,
      GWL_USERDATA,
      ( LONG ) pData );
}

void * hbDockAutoHideGetUserData(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return NULL;

   return ( void * )
      GetWindowLong(
         pPane->hWnd,
         GWL_USERDATA );
}