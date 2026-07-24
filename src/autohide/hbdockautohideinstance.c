#include <windows.h>

#include "hbdockautohideinstance.h"

HINSTANCE hbDockAutoHideGetInstance(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return NULL;

   if( pAutoHide->Panel == NULL )
      return NULL;

   if( pAutoHide->Panel->hWnd == NULL )
      return NULL;

   return ( HINSTANCE )
      GetWindowLong(
         pAutoHide->Panel->hWnd,
         GWL_HINSTANCE );
}