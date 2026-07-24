#include <windows.h>

#include "hbdockautohidemessage.h"

LRESULT hbDockAutoHideSendMessage(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam )
{
   if( pAutoHide == NULL )
      return 0;

   if( pAutoHide->Panel == NULL )
      return 0;

   if( pAutoHide->Panel->hWnd == NULL )
      return 0;

   return SendMessage(
      pAutoHide->Panel->hWnd,
      uMsg,
      wParam,
      lParam );
}


BOOL hbDockAutoHidePostMessage(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam )
{
   if( pAutoHide == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   return PostMessage(
      pAutoHide->Panel->hWnd,
      uMsg,
      wParam,
      lParam );
}