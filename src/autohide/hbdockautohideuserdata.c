#include <windows.h>

#include "hbdockautohideuserdata.h"


void hbDockAutoHideSetUserData(
   HB_DOCK_AUTOHIDE * pAutoHide,
   void * pData )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SetWindowLong(
      pAutoHide->Panel->hWnd,
      GWL_USERDATA,
      ( LONG ) pData );
}


void * hbDockAutoHideGetUserData(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return NULL;

   if( pAutoHide->Panel == NULL )
      return NULL;

   if( pAutoHide->Panel->hWnd == NULL )
      return NULL;

   return ( void * )
      GetWindowLong(
         pAutoHide->Panel->hWnd,
         GWL_USERDATA );
}