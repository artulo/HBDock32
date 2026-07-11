#include "hbdockautohidepressed.h"

void hbDockAutoHideSetPressed(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int bPressed )
{
   if( pPane != NULL )
      pPane->Pressed = bPressed;
}

int hbDockAutoHideIsPressed(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Pressed;
}