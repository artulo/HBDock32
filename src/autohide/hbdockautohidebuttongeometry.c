#include <windows.h>

#include "hbdockautohidebuttongeometry.h"

BOOL hbDockAutoHideButtonGetRect(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   RECT * pRect )
{
   if( pButton == NULL || pRect == NULL )
      return FALSE;

   return GetWindowRect(
      pButton->hWnd,
      pRect );
}

BOOL hbDockAutoHideButtonSetRect(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   const RECT * pRect,
   BOOL bRepaint )
{
   if( pButton == NULL || pRect == NULL )
      return FALSE;

   return MoveWindow(
      pButton->hWnd,
      pRect->left,
      pRect->top,
      pRect->right - pRect->left,
      pRect->bottom - pRect->top,
      bRepaint );
}
