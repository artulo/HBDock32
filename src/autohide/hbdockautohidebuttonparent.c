#include <windows.h>

#include "hbdockautohidebuttonparent.h"

#ifndef HB_SYMBOL_UNUSED
#define HB_SYMBOL_UNUSED(x) ((void)(x))
#endif

HWND hbDockAutoHideButtonGetParent(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   HB_SYMBOL_UNUSED( pButton );

   return NULL;
}

void hbDockAutoHideButtonSetParent(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   HWND hParent )
{
   HB_SYMBOL_UNUSED( pButton );
   HB_SYMBOL_UNUSED( hParent );
}