#include <windows.h>

#include "hbdockautohidemessage.h"

LRESULT hbDockAutoHideSendMessage(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam )
{
   if( pPane == NULL )
      return 0;

   return SendMessage(
      pPane->hWnd,
      uMsg,
      wParam,
      lParam );
}

BOOL hbDockAutoHidePostMessage(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam )
{
   if( pPane == NULL )
      return FALSE;

   return PostMessage(
      pPane->hWnd,
      uMsg,
      wParam,
      lParam );
}