#include <windows.h>

#include "hbdockautohidevisible.h"


void hbDockAutoHideShowWindow(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   ShowWindow(
      pAutoHide->Panel->hWnd,
      SW_SHOW );
}


void hbDockAutoHideHideWindow(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   ShowWindow(
      pAutoHide->Panel->hWnd,
      SW_HIDE );
}


BOOL hbDockAutoHideWindowVisible(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   return IsWindowVisible(
      pAutoHide->Panel->hWnd );
}