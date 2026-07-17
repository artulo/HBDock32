#include <windows.h>

#include "hbdockautohidebuttonstyle.h"

#ifndef HB_SYMBOL_UNUSED
#define HB_SYMBOL_UNUSED(x) ((void)(x))
#endif

DWORD hbDockAutoHideButtonGetStyle(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   HB_SYMBOL_UNUSED( pButton );
   return 0;
}

void hbDockAutoHideButtonSetStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   DWORD dwStyle )
{
   HB_SYMBOL_UNUSED( pButton );
   HB_SYMBOL_UNUSED( dwStyle );
}

DWORD hbDockAutoHideButtonGetExStyle(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   HB_SYMBOL_UNUSED( pButton );
   return 0;
}

void hbDockAutoHideButtonSetExStyle(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   DWORD dwExStyle )
{
   HB_SYMBOL_UNUSED( pButton );
   HB_SYMBOL_UNUSED( dwExStyle );
}