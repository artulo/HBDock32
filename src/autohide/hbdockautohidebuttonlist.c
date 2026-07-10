#include "hbdockautohidebuttonlist.h"

int hbDockAutoHideButtonAdd(
   HB_DOCK_AUTOHIDE_STRIP * pStrip,
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   return hbDockArrayAdd(
      &pStrip->Buttons,
      pButton );
}

int hbDockAutoHideButtonRemove(
   HB_DOCK_AUTOHIDE_STRIP * pStrip,
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   int i;

   for( i = 0; i < pStrip->Buttons.Count; ++i )
   {
      if( hbDockArrayGet(
             &pStrip->Buttons,
             i ) == pButton )
         return hbDockArrayRemove(
            &pStrip->Buttons,
            i );
   }

   return 0;
}

HB_DOCK_AUTOHIDE_BUTTON *
hbDockAutoHideButtonGet(
   HB_DOCK_AUTOHIDE_STRIP * pStrip,
   int nIndex )
{
   return
      ( HB_DOCK_AUTOHIDE_BUTTON * )
      hbDockArrayGet(
         &pStrip->Buttons,
         nIndex );
}