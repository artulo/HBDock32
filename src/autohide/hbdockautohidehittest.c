#include <windows.h>

#include "hbdockautohidehittest.h"

HB_DOCK_AUTOHIDE_BUTTON *
hbDockAutoHideHitTest(
   HB_DOCK_AUTOHIDE_STRIP * pStrip,
   POINT pt )
{
   int i;

   for( i = 0; i < pStrip->Buttons.Count; ++i )
   {
      HB_DOCK_AUTOHIDE_BUTTON * pButton;

      pButton =
         ( HB_DOCK_AUTOHIDE_BUTTON * )
         hbDockArrayGet(
            &pStrip->Buttons,
            i );

      if( pButton != NULL )
      {
         if( PtInRect(
                &pButton->Rect,
                pt ) )
            return pButton;
      }
   }

   return NULL;
}