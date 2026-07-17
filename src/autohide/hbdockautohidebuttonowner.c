#include <windows.h>

#include "hbdockautohidebuttoninstance.h"

#ifndef HB_SYMBOL_UNUSED
#define HB_SYMBOL_UNUSED(x) ((void)(x))
#endif

HINSTANCE hbDockAutoHideButtonGetInstance(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   HB_SYMBOL_UNUSED( pButton );

   return GetModuleHandle( NULL );
}