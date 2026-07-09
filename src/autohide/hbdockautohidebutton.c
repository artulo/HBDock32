#include <string.h>

#include "hbdockautohidebutton.h"

void hbDockAutoHideButtonInit(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   memset(
      pButton,
      0,
      sizeof( HB_DOCK_AUTOHIDE_BUTTON ) );
}