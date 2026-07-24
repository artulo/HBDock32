#include <windows.h>

#include "hbdockautohidegeometry.h"

BOOL hbDockAutoHideGetWindowRect(
   HB_DOCK_AUTOHIDE * pAutoHide,
   RECT * pRect )
{
   if( pAutoHide == NULL || pRect == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   return GetWindowRect(
      pAutoHide->Panel->hWnd,
      pRect );
}


BOOL hbDockAutoHideSetWindowRect(
   HB_DOCK_AUTOHIDE * pAutoHide,
   const RECT * pRect,
   BOOL bRepaint )
{
   if( pAutoHide == NULL || pRect == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   return MoveWindow(
      pAutoHide->Panel->hWnd,
      pRect->left,
      pRect->top,
      pRect->right - pRect->left,
      pRect->bottom - pRect->top,
      bRepaint );
}