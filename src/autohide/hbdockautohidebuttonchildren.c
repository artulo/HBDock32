#include <windows.h>

#include "hbdockautohidebuttonchildren.h"

#ifndef HB_SYMBOL_UNUSED
#define HB_SYMBOL_UNUSED(x) ((void)(x))
#endif

HWND hbDockAutoHideButtonGetFirstChild(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   HB_SYMBOL_UNUSED( pButton );

   return NULL;
}

HWND hbDockAutoHideButtonGetNextSibling(
   HWND hWnd )
{
   HB_SYMBOL_UNUSED( hWnd );

   return NULL;
}

HWND hbDockAutoHideButtonGetPreviousSibling(
   HWND hWnd )
{
   HB_SYMBOL_UNUSED( hWnd );

   return NULL;
}