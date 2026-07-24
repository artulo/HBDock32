#include <windows.h>

#include "hbdockautohidewindow.h"


HWND hbDockAutoHideGetWindow(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return NULL;

   if( pAutoHide->Panel == NULL )
      return NULL;

   return pAutoHide->Panel->hWnd;
}


BOOL hbDockAutoHideIsWindow(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   return IsWindow(
      pAutoHide->Panel->hWnd );
}