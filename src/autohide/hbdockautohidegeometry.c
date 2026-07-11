#include <windows.h>

#include "hbdockautohidegeometry.h"

BOOL hbDockAutoHideGetWindowRect(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   RECT * pRect )
{
   if( pPane == NULL || pRect == NULL )
      return FALSE;

   return GetWindowRect(
      pPane->hWnd,
      pRect );
}

BOOL hbDockAutoHideSetWindowRect(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   const RECT * pRect,
   BOOL bRepaint )
{
   if( pPane == NULL || pRect == NULL )
      return FALSE;

   return MoveWindow(
      pPane->hWnd,
      pRect->left,
      pRect->top,
      pRect->right - pRect->left,
      pRect->bottom - pRect->top,
      bRepaint );
}