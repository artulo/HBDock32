#include <windows.h>

#include "hbdockautohidepaint.h"
#include "hbdockautohidebutton.h"

void hbDockAutoHideStripPaint(
   HB_DOCK_AUTOHIDE_STRIP * pStrip,
   HDC hDC )
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
         Rectangle(
            hDC,
            pButton->Rect.left,
            pButton->Rect.top,
            pButton->Rect.right,
            pButton->Rect.bottom );
      }
   }
}