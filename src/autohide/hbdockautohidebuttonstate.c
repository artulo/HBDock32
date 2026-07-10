#include "hbdockautohidebuttonstate.h"

void hbDockAutoHideButtonSetHot(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   int bHot )
{
   if( pButton != NULL )
      pButton->Hot = bHot;
}

void hbDockAutoHideButtonSetPressed(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   int bPressed )
{
   if( pButton != NULL )
      pButton->Pressed = bPressed;
}

int hbDockAutoHideButtonIsHot(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return pButton->Hot;
}

int hbDockAutoHideButtonIsPressed(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return pButton->Pressed;
}