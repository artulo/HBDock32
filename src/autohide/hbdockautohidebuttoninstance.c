#include <windows.h>

#include "hbdockautohidebuttoninstance.h"

HINSTANCE hbDockAutoHideButtonGetInstance(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return NULL;

   return ( HINSTANCE )
      GetWindowLong(
         pButton->hWnd,
         GWL_HINSTANCE );
}