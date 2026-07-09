#include "hbdockautohidelayout.h"
#include "hbdockautohidebutton.h"

void hbDockAutoHideStripLayout(
   HB_DOCK_AUTOHIDE_STRIP * pStrip,
   const RECT * pRect )
{
   int i;
   int x;

   x = pRect->left + 2;

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
         pButton->Rect.left = x;
         pButton->Rect.top = pRect->top + 2;
         pButton->Rect.right = x + 80;
         pButton->Rect.bottom = pRect->bottom - 2;

         x += 82;
      }
   }
}