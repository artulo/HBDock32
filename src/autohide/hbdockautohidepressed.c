#include "hbdockautohidepressed.h"

void hbDockAutoHideSetPressed(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int bPressed )
{
   if( pAutoHide != NULL )
      pAutoHide->Pressed = bPressed;
}

int hbDockAutoHideIsPressed(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return FALSE;

   return pAutoHide->Pressed;
}