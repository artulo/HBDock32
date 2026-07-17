#include <windows.h>

#include "hbdockautohidefocusbutton.h"

#ifndef HB_SYMBOL_UNUSED
#define HB_SYMBOL_UNUSED(x) ((void)(x))
#endif

void hbDockAutoHideFocusButton(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   HB_SYMBOL_UNUSED( pButton );
}

int hbDockAutoHideButtonHasFocus(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   HB_SYMBOL_UNUSED( pButton );
   return 0;
}