#include <string.h>

#include "hbdockautohidepane.h"

void hbDockAutoHidePaneInit(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   memset(
      pPane,
      0,
      sizeof(
         HB_DOCK_AUTOHIDE_PANE ) );
}