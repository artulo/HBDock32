#include <windows.h>

#include "hbdockautohideinstance.h"

HINSTANCE hbDockAutoHideGetInstance(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return NULL;

   return ( HINSTANCE )
      GetWindowLong(
         pPane->hWnd,
         GWL_HINSTANCE );
}